#include <iostream>
#include <cstring>

int str_len(const char* str){
    int len = 0;
    while(*str){
        ++len;
        ++str;
    }
    return len;
}
void reverse_str(char* str){
    int len = str_len(str);
    for(int i = 0; i < len/2; ++i){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
bool isPalindrome(const char* str){
    int len = str_len(str);
    for(int i = 0; i < len/2; ++i){
        if(str[i] != str[len-1-i]) return false;
    }
    return true;
}
void toggleCase(char* str){
    while (*str)
    {
        if(*str >= 'a' && *str <= 'z'){
            *str = *str - ('a' - 'A');
        }
        else if(*str >= 'A' && *str <= 'Z'){
            *str = *str + ('a' - 'A');
        }
        ++str;
    }
}
int str_cmp(const char* str1, const char* str2){
    while (*str1 && *str2)
    {
        if(*str1 < *str2) return -1;
        else if(*str1 > *str2) return 1;
        ++str1;
        ++str2;
    }
    return (*str1-*str2);
}

void removeDuplicates(char* str){

    int len = str_len(str);
    bool contentVector[256] = {false};

    char* result = new char[len + 1] {'\0'};
    int i;
    for(int j = 0, i = 0; j < len; ++j)
    {
        if(!contentVector[str[j]]){
            contentVector[str[j]] = 1;
            result[i] = str[j];
            ++i;
        }
    }


    for(int i = 0; i < len; ++i) {
        str[i] = result[i];
    }
    

    std::cout << "Res: " << result << std::endl;
    std::cout << "Str: " << str << std::endl;

    //strcpy_s(str, len, result);
    delete[] result;
}

int main(){
    char str[] = "Hello world!!";
    

    //std::cout<<(str_len(str));
    //toggleCase(str);
    //std::cout<<(76&(-1));
    //std::cout<<(str_cmp("aalaat", "aalaa"));
    removeDuplicates(str);
    std::cout << "in main: "<< str << '\n';
    return 0;
}