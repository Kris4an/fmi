#include <iostream>
#include <cmath>

int main(){
    int n;
    std::cin>>n;
    int* A = new int[n];

    for(int i = 0; i < n; ++i) {
        std::cin>>A[i];
        A[i]+=1;
    }

    for(int i = 0; i < n; ++i){
        if(abs(A[i]-1) <= n){
            if(A[abs(A[i])-1] >= 0) A[abs(A[i])-1]*=-1;
        }  
    }

    for(int i = 0; i < n; ++i){
        if(A[i]>0){
            std::cout<<i<<'\n';
            return 0;
        }
    }
    std::cout<<n;
    return 0;
}