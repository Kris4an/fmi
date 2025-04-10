#include <iostream>
#include <limits>

bool isPowerOf2(int a){
    return (a&(a-1)) == 0;
}
int zad2(int n){
    int i = 0;
    for(;n>1;++i) {
        n = n>>1;
    }
    return (n<<i+1);
}
int zad3(int n){
    if(isPowerOf2(n)) return (n>>1);
    int i = 0;
    for(;n>1;++i) {
        n = n>>1;
    }
    return (n<<i);
}
int zad4(unsigned int n, unsigned int k){
    return ((n>>(k-1))&1);
}
int zad5(int n){
    int cnt = 0;
    while(n>0){
        if(n&1 == 1) ++cnt;
        n = n>>1;
    }
    return cnt;
}
int flipBit(int n, int k){
    int back = 0;
    for(int i = 0; i < k-1; i++){
        back = back|((n&1)<<i);
        n = n>>1;
    }
    int kBit = n&1;
    if(kBit){
        n = n>>1;
        n = n<<1;
    }
    else n = n|1;
    n = n << (k-1);
    n = n|back;
    return n;
}
int zad6(int n, int i, int j){
    int iBit = zad4(n, i);
    int jBit = zad4(n, j);
    if(iBit == jBit) return n;
    n = flipBit(n, i);
    n = flipBit(n, j);
    return n;
}
int main(){
    std::cout<<(zad4(8,4));
    //std::cout<<(flipBit(9, 2));
    //std::cout<<(zad6(16, 2, 5));
    return 0;
}