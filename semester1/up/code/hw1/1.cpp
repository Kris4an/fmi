#include <iostream>
#include <math.h>

int main(){
    int n;
    int sum = 1;
    std::cin>>n;
    bool isPrime = true;
    if(n < 1) return 0;
    if(n == 1){
        std::cout<<"Not Prime\n0";
        return 0;
    }
    if(n == 2){
        std::cout<<"Prime\nnull 3";
        return 0;
    }
    if(n == 3){
        std::cout<<"Prime\n2 5";
        return 0;
    }

    for(int i = 2; i <= n/2; ++i){
        if(n%i==0){
            isPrime = false;
            sum+=i;
        }
    }
    if(isPrime){
        int upperPrime, lowerPrime;
        for(int i = n+2; true; i+=2){
            upperPrime = i;
            for(int j = 3; j <= sqrt(i); j+=2){
                if(i%j==0){
                    upperPrime = 0;
                    break;
                }
            }
            if(upperPrime){
                break;
            }
        }
        for(int i = n-2; true; i-=2){
            lowerPrime = i;
            for(int j = 3; j <= sqrt(i); j+=2){
                if(i%j==0){
                    lowerPrime = 0;
                    break;
                }
            }
            if(lowerPrime){
                break;
            }
        }
        std::cout<<"Prime\n"<<lowerPrime<<" "<<upperPrime;
    }
    else{
        std::cout<<"Not Prime\n"<<sum;
    }
    return 0;
}