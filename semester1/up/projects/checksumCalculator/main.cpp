#include <iostream>
#include <fstream>
#include <string>
#include "calculator.h"
#include "algorithms/SHA256.h"
#include <filesystem>

using namespace std;

Calculator calculator;
const char *verificationText = "checksum-calculator";

const int inputSize = 3;
string input[inputSize] = {""};

void printChecksum(string hash, string path){
    cout << hash << " *" << path << std::endl;
}

void calculateChecksumForFile(string path, Algorithms algorithm, bool binaryMode){
    ifstream file;

    if(binaryMode) file.open(path, ios::binary);
    else file.open(path);

    if(!(file.is_open())){
        std::cerr << "Error opening file at path " << path << std::endl;
        return;
    }

    string hash = calculator.calculateChecksum(file, algorithm);

    file.close();

    printChecksum(hash, path);
}

void calculateChecksum()
{
    string path = input[1];
    string calculatorMode = input[0];
    bool binaryMode = false;
    
    if(input[2] == "-b") binaryMode = true;
    
    Algorithms algorithm;
    
    if (calculatorMode == "sha256")
        algorithm = Algorithms::sha256;
    else
    {
        cout << "Incorrect algorithm! "<< calculatorMode << " is not a valid algorithm!" << std::endl;
        return;
    }

    if(path.back() == '*'){
        path = path.substr(0, path.length() - 1);
        
        for (const auto & entry : filesystem::directory_iterator(path)){
            if(!entry.is_directory()) calculateChecksumForFile(entry.path().string(), algorithm, binaryMode);
        }

    }
    else{
        calculateChecksumForFile(path, algorithm, binaryMode);
    }

}

int main()
{

    while (true)
    {
        string inputLine;
        getline(std::cin, inputLine);

        if(inputLine == "exit") return 0;

        for(int i = 0; i < inputSize; ++i) input[i] = "";

        int i = 0;
        for(int pos = inputLine.find(' '); pos != string::npos; ++i){

            input[i] = inputLine.substr(0, pos);
            inputLine.erase(0, pos + 1);
            pos = inputLine.find(' ');

        }
        input[i] = inputLine;

        string calculatorMode = input[0];

        if (calculatorMode == verificationText)
        {
        }
        else
        {
            calculateChecksum();
        }
        
        cout<<endl;
    }

    return 0;
}