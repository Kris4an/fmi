#include <iostream>
#include <math.h>

unsigned int zad0(int a){
    return (a>0)? a:-1*a;
}
int zad1(int n){
    return (n+1)*n/2;
}
int zad2(int a, int b){
    int c = 0;
    while (a>0)
    {
        if(a%10==b) c++;
        a=a/10;
    }
    return c;
}
void zad3(unsigned int a, unsigned int b){
    std::cout<<"[";
    for(int i = a; i<b; ++i){
        std::cout<<i<<",";
    }
    std::cout<<b<<"]";
}
bool zad4(int a){
    int b = 0, c = a;
    for(int c = a; c>0; c=c/10){
        b=b*10+(c%10);
    }
    return b==a;
}
int zad6(int n, int k){
    int res = 1;
    for(int i = 0; i<k-1; ++i){
        res = res*(n-i)/(i+1);
    }
    return res;
}
bool isPrime(int a){
    if(a == 2) return true;
    if(a%2==0) return false;
    for(int i = 3; i<a/2; i+=2){
        if(a%i==0) return false;
    }
    return true;
}
void zad9(int a, int b){
    for(int i = a; i <= b; ++i){
        int nc = floor(log10(i))+1;
        bool flag = true;
        int v = i;
        for(int j = 0; j <= nc; j++){
            v = v/10 + (v%10)*pow(10, nc-1);
            if(!isPrime(v)) {
                flag = false;
                break;
            }
        }

        if(flag){
            std::cout<<i<<'\n';
        }
    }
}
void zad8(int n){
    for(int i = 1; i<=n/2; i+=2){
        if(isPrime(i)){
            if(isPrime(n-i)) std::cout<<"<"<<i<<","<<(n-i)<<">"<<'\n';
        }
    }
}
void zad7(int a, int b){
    for(int i = a; i <= b; ++i){
        int s = 1;
        for(int j = 2; j <= i/2; ++j){
            if(i%j==0) s+=j;
        }
        if(s==i) std::cout<<i<<'\n';
    }
}
int main(){
    //std::cout<<(zad2(12342,6));
    //std::cout<<(zad6(5,3));
    //zad8(3434);
    zad7(2,9000);
    return 0;
}