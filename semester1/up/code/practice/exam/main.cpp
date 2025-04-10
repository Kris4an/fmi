#include <iostream>
#include <math.h>

void zad1(){
    int a, b, A = 1, B = 1;
    std::cin>>a>>b;

    while(a > 0){
        A*=a%10;
        a/=10;
    }
    while(b > 0){
        B*=b%10;
        b/=10;
    }

    std::cout<<(A==B? "true":"false");
}
int zad2(int n){
    int res = 0, m = 1;
    for(int i = 1; n > 0; ++i){
        int t = n%10 + i;
        res+=t*m;
        m*=10;
        n/=10;
        if(t>9){
            m*=10;
        }
    }
    return res;
}
bool isAj(int n){
    int prev = n%10;
    n/=10;
    for(; n > 0; n/=10){
        if(n%10 == prev) return false;
        prev = n % 10;
    }
    return true;
}
void zad3(){
    int a,b;
    int min = b; int max = a;
    std::cin>>a>>b;
    for(int i = a; i < b; ++i){
        if(isAj(i)){
            if(i < min) min = i;
            if(i > max) max = i;
        }
    }
    if(min>max) std::cout<<"No adjacent numbers!";
    else std::cout<<(max-min);
}
void zad4(){
    int n;
    std::cin>>n;
    int cnt = floor(log10(n));
    while(n>0){
        int t = n/(int)pow(10, cnt);
        if(t % 2 == 0) std::cout<<t;
        n%= (int)pow(10, cnt);
        --cnt;
    }
}
void zad5(int n){
    int ch = 10;
    for(int i = 1; i < n; ++i){
        ch = pow(10, floor(log10(i)) + 1);
        if(i*(i-1)%ch==0) std::cout<<i<<'\n';
    }
}
void zad0(){
    int n;
    std::cin>>n;

    int avg = 0, cnt6 = 0, cnt2 = 0;

    for(int i = 0; i < n; ++i){
        int t;
        std::cin>>t;
        switch (t)
        {
        case 6:
            ++cnt6;
            break;
        case 2:
            ++cnt2;
            break;
        }
        avg+=t;
    }
    std::cout<<"Брой отлични оценки: "<<cnt6<<"\nСредна оценка: "<<(avg/n)<<"\n% слаби оценки: "<<((double)cnt2/n)*100<<"%";
}
int main(){
    //zad0();
    zad5(150);
    return 0;
}