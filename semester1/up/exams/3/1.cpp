//Име: Кристиан Христакиев
//ФН: 6MI0800608
//Група: 8
#include <iostream>

double average(double n){
    static double sum = 0;
    static int count = 0;
    ++count;
    sum+=n;
    return sum/count;
}

int main(){
    std::cout << average(5) << std::endl;  // извежда 5, защото 5/1 = 5
    std::cout << average(10) << std::endl; // извежда 7.5, защото (5+10)/2 = 7.5
    std::cout << average(0) << std::endl;  // извежда 5, защото (5+10+0)/3 = 5
    std::cout << average(-5) << std::endl; // извежда 2.5, защото (5+10+0-5)/4 = 2.5
    return 0;
}