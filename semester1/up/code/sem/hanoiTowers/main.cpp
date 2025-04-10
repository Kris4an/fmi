#include <iostream>

int hanoiTotal(int n){
    if(n == 1) return 1;
    return 2*hanoiTotal(n-1) + 1;
}

int main(){
    std::cout<<(hanoiTotal(4));
    return 0;
}