#include <iostream>

/*
Препроцосорът замества define-натия текст (той не разбира езика)
*/
#define XYZ 123
#define abc 2 + 2
#define PRINT(x) std::cout<<x;

inline /*компилаторъ решава дали се inline-ва, незаевисимо какво е написано*/ void print(int a){ 
    std::cout << a;
}

void small_func();
void heavy_ass_func();

inline int x; //може да се достъпва от всички cpp факлове

int main(){
    std::cout << XYZ; // std::cout << 123;
    std::cout << '\n';
    std::cout << abc * 2; // std::cout << 2 + 2 * 2
    std::cout << '\n';
    PRINT("hello"); // std::cout << "hello";

    print(5); // -> кодът на функцията ще бъде наблъскан тук

    for(int i = 0; i < 1'000'000'000; ++i){
        if(i = 500'000'000) heavy_ass_func(); //не се inline-ва
        small_func(); //добре да се inline-не
    }
}