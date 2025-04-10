#include <iostream>

void zad1(int n){  
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n*4-1; ++j){
            if(j%2!=0 && j > i*2 && j < n*4-1-i*2) std::cout<<"^";
            else std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    for(int i = n-2; i >= 0; --i){
        for(int j = 0; j < n*4-1; ++j){
            if(j%2!=0 && j > i*2 && j < n*4-1-i*2) std::cout<<"^";
            else std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n  = 3;
    //std::cin>>n;
    zad1(n);
    return 0;
}