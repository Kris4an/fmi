#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

int main(){
    std::ifstream file;
    std::string input;
    std::getline(std::cin, input);
    file.open(input);
    if(!file) std::cout<<"kys";
}