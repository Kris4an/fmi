#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
class Foo{
    int* data;
    size_t size;
public:
    int& at(size_t index)
    {
        if(index >= size) throw std::invalid_argument(":(");

        return data[index];
    }

    const int& at(size_t index) const
    {
        //имаме const pointer към this, защото at метода е const
        //превръщаме го във Foo*, за да викнем не-const версията на метода
        return const_cast<Foo*>(this)->at(index);
    }
};

class box{
    int data;
public:
    box() : data(0) {}
    explicit box(int value) : data(value) {}
    operator int() {return data;}\
    operator std::string() 
    {
        std::ostringstream os;
        os << data;
        return os.str();
    }
    box& operator=(int value) {
        data = value;
        return *this;
    }
};

void f(const int& param)
{
    std::cout << param;

    int ref = const_cast<int&>(param);
    ref = 23;
}

void test(box b){
    
}


class multiply{
    int by;
public:
    multiply(int by) : by(by) {}

    int calculate(int x) {
        return x * by;
    }

    int operator()(int x) {
        return x * by;
    }

    int operator()(int x, int y) {
        return x * y * by;
    }
};

int main()
{
    int var = 42;
    f(var); // -> f(const_cast<const int&>(var));

    std::cout << var;

    //static_cast<>
    int v = 42;
    double d1 = v;
    double d2(v);
    int(5.5);
    
    box b(42);
    int x = b;
    x = b;

    std::string str = b;

    box g(v);
    g = v;

    multiply multiplyBy5(5);

    std::cout << multiplyBy5.calculate(10) << std::endl;
    std::cout << multiplyBy5(10) << std::endl;
    std::cout << multiplyBy5(100, 6);
}