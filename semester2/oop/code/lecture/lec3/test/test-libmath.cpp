#include <iostream>
#include <limits>

#include "../libmath/math.h"

//int factorial(int);

void reportResult(bool status, const char* functionName){
    std::cout 
        << (status? "[ OK ]" : "[ FAILED ]") 
        << functionName
        << std::endl;
}

void factorial_returnsMinusForNegativeValues()
{
    bool check = (
        factorial(-5) == -1 &&
        factorial(-1) == -1 &&
        factorial(-10000) == -1
    );

    reportResult(check, __FUNCTION__);
}

void factorial_returnsMinus2OnOverflow()
{
    bool check = true;
    
    const int maxInt = std::numeric_limits<int>::max();

    check = (factorial(maxInt / 2) == -2);

    reportResult(check, __FUNCTION__);
}

void factorial_returnsCorrectValuesForValidInputs()
{
    bool check = true;

    int sampleSize= 6;
    int expected[] = {
        1,
        1,
        2,
        6,
        24,
        120
    };

    for(int i = 0; i < sampleSize; ++i){
        check = check && (factorial(i) == expected[i]);
    }

    reportResult(check, __FUNCTION__);
}

int main(){
    factorial_returnsCorrectValuesForValidInputs();
    factorial_returnsMinus2OnOverflow();
    factorial_returnsMinusForNegativeValues();
}







//___________________

using testfn_ptr = void(*)(void);

int registerTest(testfn_ptr ptr, const char* name);

void someTest(void);
int __var__someTest = registerTest(someTest, "someTest");
void someTest(void){

}

//използвай catch2