#include <iostream>

void printArray(int* arr, int size){
    if(size < 1) return;
    std::cout<<"{"<<arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] != NULL) std::cout<<","<<arr[i];
    }
    std::cout<<"}\n";
}

void subsets(int* arr, int size){
    if(size == 0) return;
    printArray(arr, size);
    int* newArr = new int[size - 1];
    for(int i = 0; i < size; ++i){
        //for(int j = 0; j < size)
    }
}

void zad9(int* arr, int size){
    std::cout<<"{}\n";
    subsets(arr, size);
}

int main(){

    return 0;
}