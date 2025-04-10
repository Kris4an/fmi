#include <iostream>

bool isWhitespace(char c){
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

char* normalizeWhitespace(char* str){
    char* start = str;
    char* read = str;
    char* write = str;

    bool previousIsWhitespace = false;
    bool allowWhitespace = false;

    while(*read != '\0'){
        if(isWhitespace(*read)){
            if(!previousIsWhitespace && allowWhitespace) {
                *write = ' ';
                write++;
            }
                
            previousIsWhitespace = true;
        }
        else{
            previousIsWhitespace = false;
            allowWhitespace = true;

            *write = *read;
            write++;
        }

        read++;
    }

    if(*(write-1) == ' ') write--;

    *write = '\0';

    return start;
}

int toInt(char* str){
    if(str == nullptr || *str == '\0') return 0;

    int sign = (*str == '-'? -1:1);
    int res = 0;

    if(*str == '-') str++;

    while(*str!='\0'){
        res*=10;
        res+=*str-'0';
        str++;
    }

    return sign*res;
}

int main(){
    char str[] = "  \t abc       def\t\t\tgh\r\t";
    std::cout<<normalizeWhitespace(str)<<'\n';
    std::cout<<toInt("123")<<'\n'<<toInt("")<<'\n'<<toInt(nullptr)<<'\n'<<toInt("-123");
    return 0;
}