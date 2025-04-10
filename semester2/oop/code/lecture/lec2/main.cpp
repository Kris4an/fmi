#include <iostream> //налива целия код на iostream библиотеката към компилатора в кода
//#include "something" - ползва се за написани от нас файлове

#include "library.h"

#define FLAG1

int main(){
    #if defined(FLAG1)
    std::cout<<"Somthing";
    #endif

    #ifdef FLAG2
    std::cout<<"Nqma flag2 :(";
    #endif

    std::cout<<factorial(5);
}