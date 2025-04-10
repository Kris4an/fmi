//Име: Кристиан Христакиев
//ФН: 6MI0800608
//Група: 8
#include <iostream>

unsigned int fromHex(const char* str){
    if(str == nullptr || *str == '\0') return 0;
    
    unsigned int result = 0;
    bool isLeadingZero = true;
    int charLen = 0;

    for(int i = 0; str[i] != '\0'; ++i){
        result*=16;

        if(str[i] >= '0' && str[i] <= '9'){
            result+= str[i]-'0';
        }
        else{
            result+= str[i] - 'A' + 10;
        }

        if(isLeadingZero && str[i] != '0') isLeadingZero = false;
        if(!isLeadingZero) ++charLen;
    }

    if(charLen > sizeof(unsigned int)*2) return 0;

    return result;
}


int main(){
    // допускаме, че sizeof(unsigned int) == 4
    std::cout << fromHex(nullptr) << std::endl; // извежда 0
    std::cout << fromHex("") << std::endl;      // извежда 0
    std::cout << fromHex("0") << std::endl;     // извежда 0
    std::cout << fromHex("B") << std::endl;     // извежда 11
    std::cout << fromHex("1A2B3") << std::endl; // извежда 107187
    std::cout << fromHex("00000000001A2B3") << std::endl; // извежда 107187;
    std::cout << fromHex("123456789ABCDEF") << std::endl; // извежда 0
    return 0;
}