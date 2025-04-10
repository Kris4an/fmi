//Име: Кристиан Христакиев
//ФН: 6MI0800608
//Група: 8
#include <iostream>

char* reverse(char* begin, char* end){
    if(begin == nullptr || end == nullptr || begin == end){
        return begin;
    }

    char* right = end - 1;
    char* left = begin;

    while (left < right){
        char temp = *left;
        *left = *right;
        *right = temp;
        --right;
        ++left;
    }

    return begin;
}

bool isWhitespace(char c){
    return c == ' ' || c == '\n' || c == '\t';
}

char* reverseWords(char* str){
    if(str == nullptr) return str;

    char* firstNonWhitespace = (isWhitespace(*str)? nullptr : str);
    
    for(char* ptr = str; *ptr != '\0'; ++ptr){
        if(isWhitespace(*ptr) && firstNonWhitespace != nullptr){
            reverse(firstNonWhitespace, ptr);
            firstNonWhitespace = nullptr;
        }
        else if(firstNonWhitespace == nullptr){
            firstNonWhitespace = ptr;
        }
    }

    return str;
}

int main(){
    char str[] = "abcdef";
    char str2[] = "abc defgh  \t       12345  ";

    std::cout << reverse(str, str) << std::endl;   // извежда "abcdef";
    std::cout << reverse(str, str+1) << std::endl; // извежда "abcdef";
    std::cout << reverse(str, str+2) << std::endl; // извежда "bacdef";
    std::cout << reverse(str, str+2) << std::endl; // извежда "abcdef";
    std::cout << reverse(str, str+6) << std::endl; // извежда "fedcba";

    std::cout << reverseWords(str2);
    return 0;
}