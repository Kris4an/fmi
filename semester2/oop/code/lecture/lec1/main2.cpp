#include <iostream>

#define make_var(no) int var##no;

//stringify
#define toString(x) #x
#define TRACE(x) std::cout<<#x "\n"; x;
int main(){
    int var2;

    make_var(1); // int var1;;

    std::cout<< toString(hello)<<"\n";

    TRACE(int x);
    /*
    std::cout<< "int x" "\n";
    int x;
    */
    TRACE(x = 10);
    /*
    std::cout<< "x = 10" "\n";
    x = 10;
    */
    TRACE(std::cout<<x);
    /*
    std::cout<< "std::cout<<x" "\n";
    std::cout<<x;
    */
}