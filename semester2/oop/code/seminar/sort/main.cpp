#include <iostream>
#define bSort(arr,size) \
    for(int i = 0; i < size; ++i){\
        for(int j = i; j < size; ++j){\
            if(arr[i] > arr[j]){\
                int t = arr[i];\
                arr[i] = arr[j];\
                arr[j] = t;\
            }\
        }\
    }\

void bubbleSort(int* arr, int size){
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            if(arr[i] > arr[j]){
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void print(int* arr, int size){
    for(int i = 0; i < size; ++i) std::cout<<arr[i]<<" ";
}

int main(){
    int size = 100;
    int* arr = new int[size];
    for(int i = 0; i < size; ++i){
        arr[i] = size-i;
    }

    //bubbleSort(arr, size);
    bSort(arr,size);
    print(arr, size);

}