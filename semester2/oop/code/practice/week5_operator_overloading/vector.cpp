#include "vector.hpp"

// int main(){
//     Vector v;
//     for(int i = 0; i <= 10; ++i)
//     {
//         v.push_back(10 - i);
//     }
//     v.reverse();
//     std::cout << v << std::endl;
//     Vector v1 = v.slice(2, 16);
//     std::cout << v1;
//     return 0;
// };

void Vector::copyObj(Vector& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new int[other.capacity];

    std::copy(other.arr, other.arr + capacity, this->arr);
}

void Vector::freeMemory()
{
    delete [] arr;
}

void Vector::enlarge()
{
    capacity *= 2;
    int* newArr = new int[capacity];
    
    std::copy(arr, arr + capacity/2, newArr);

    delete [] arr;

    arr = newArr;
}

void Vector::shrink()
{
    if(capacity == 8) return;
    capacity /= 2;
    int* newArr = new int[capacity];
    
    std::copy(arr, arr + capacity, newArr);

    delete [] arr;

    arr = newArr;
}

Vector::Vector(int size, int capacity, int* arr)
{
    this->size = size;
    this->capacity = capacity;
    this->arr = arr;
}

Vector::Vector()
{
    size = 0;
    capacity = 8;
    arr = new int[8];
};

Vector::Vector(Vector& other)
{
    copyObj(other);
};

Vector::~Vector()
{
    freeMemory();
};

Vector& Vector::operator=(Vector& other)
{
    if(this == &other) return *this;

    copyObj(other);

    return *this;
};

int Vector::operator[](int index)
{
    return at(index);
};

bool Vector::operator==(Vector& other)
{
    if(*this == other) return true;
    if(this->size != other.size) return false;
    
    for(int i = 0; i < this->size; ++ i)
    {
        if(this->arr[i] != other.arr[i]) return false;
    }

    return true;
};

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << "[";
    for(int i = 0; i < v.size-1; ++ i)
    {
        os << v.arr[i] << ",";
    }
    if(v.size >= 1) os << v.arr[v.size - 1];
    os << "]";

    return os;
}

int Vector::operator*(Vector& other)
{
    int minSize = (this->size < other.size)? this->size : other.size;
    int result = 0;
    for(int i = 0; i < minSize; ++i)
    {
        result += this->arr[i]*other.arr[i];
    }
    return result;
};

void Vector::push_back(int value)
{
    if(size == capacity) enlarge();
    arr[size] = value;
    ++size;
};

void Vector::pop_back()
{
    if(size == 0) throw std::out_of_range("Cannot pop an element out of an empty vector");
    --size;
    if(size <= capacity/4) shrink();
};

int Vector::at(int index) const
{
    if(index >= size || index < 0) throw std::invalid_argument("Invalid index, cannot get element at position " + index);
    return arr[index];
};

void Vector::insertAt(int index, int value)
{
    if(index > size || index < 0) throw std::invalid_argument("Invalid index, cannot insert at position " + index);
    if(size == capacity) enlarge();

    for(int i = size; i > index; --i)
    {
        arr[i] = arr[i-1];
    }

    ++size;
    arr[index] = value;
};

void Vector::deleteAt(int index)
{
    if(index >= size || index < 0) throw std::invalid_argument("Invalid index, no element to delete at position " + index);
    --size;
    if(size <= capacity/4) shrink();

    for(int i = index; i < size; ++i)
    {
        arr[i] = arr[i+1];
    }

};

int Vector::getCapacity() const 
{
    return capacity;
}

int Vector::getSize() const
{
    return size;
}
void Vector::sort()
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] < arr[i])
            {
                arr[j] = arr[j] ^ arr[i];
                arr[i] = arr[j] ^ arr[i];
                arr[j] = arr[j] ^ arr[i];
            }
        }
    }
};
void Vector::concat(Vector& other)
{
    int newSize = this->size + other.size;
    int newCapacity = this->capacity > other.capacity? this->capacity : other.capacity;
    if(newSize > newCapacity) newCapacity*=2;

    
    int* newArr = new int[newCapacity];
    std::copy(arr, arr + size, newArr);

    for(int i = size; i < newSize; ++i)
    {
        newArr[i] = other.arr[i - size];
    }

    freeMemory();
    this->size = newSize;
    this->capacity = newCapacity;
    arr = newArr;
};
Vector Vector::slice(int start, int end)
{
    if(start < 0) throw std::invalid_argument("Start position cannot be less than 1");
    if(end > size) throw std::invalid_argument("End position cannot be bigger than size");
    if(start == size) throw std::invalid_argument("Start position cannot be equal to the size");
    if(start > end) throw std::invalid_argument("Start position cannot be bigger than end position");
    
    int newSize = end - start;
    int newCapacity = capacity;

    while(newSize <= newCapacity/2 && newCapacity >= 16) newCapacity/=2;

    int* newArr = new int[newCapacity];
    std::copy(arr + start, arr + end, newArr);

    Vector v(newSize, newCapacity, newArr);
    return v;
};
void Vector::reverse()
{
    for(int i = 0; i < size/2; ++i)
    {
        int j = size - i - 1;
        arr[j] = arr[j] ^ arr[i];
        arr[i] = arr[j] ^ arr[i];
        arr[j] = arr[j] ^ arr[i];
    }
};