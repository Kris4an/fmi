#include <iostream>

int main(){
    int x, y;
    int N;
    std::cin>>x>>y>>N;
    for(; N > 0; --N){
        int x1, y1;
        std::cin>>x1>>y1;
        if(x == x1 && y == y1){
            std::cout<<"Tresure found";
            return 0;
        }
        if(y1 < y){
            std::cout<<"North";
            if(x1 < x) std::cout<<"east\n";
            else if(x1 > x) std::cout<<"west\n";
            else std::cout<<'\n';
        }
        else if(y1 > y){
            std::cout<<"South";
            if(x1 < x) std::cout<<"east\n";
            else if(x1 > x) std::cout<<"west\n";
            else std::cout<<'\n';
        }
        else{
           if(x1 < x) std::cout<<"East\n";
            else std::cout<<"West\n"; 
        }

    }
    return 0;
}