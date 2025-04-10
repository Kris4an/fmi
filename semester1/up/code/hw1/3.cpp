#include <iostream>
#include <cmath>
const double PRECISION = 0.00001;
int main(){
    int M, cnt1 = 0, cnt2 = 0;
    double N, Nf;

    std::cin>>N;
    std::cin>>M;
    Nf = N * 1.8 + 32.0;

    for(;M > 0; --M){
        double temp;
        std::cin>>temp;
        if(fabs(Nf-temp) < PRECISION) ++cnt1; 
        else if(fabs(Nf-temp) < 5.0) ++cnt2;
    }

    std::cout<<cnt1<<' '<<cnt2;
    return 0;
}