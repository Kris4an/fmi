#include <iostream>

int foo(int* arr, int size){
    //if(size < 1) return 0;
    int max = *arr;

    for(int i = 1; i < size; ++i){
        if(arr[i] > max) max = arr[i];
    }

    return max;
}

bool fooTest(int* arr, int size, int expRes, const char* successfulMessage, const char* errorMessage){
    int res = foo(arr, size);
    if(res == expRes) {
        std::cout<<successfulMessage<<std::endl;
        return true;
    }

    std::cerr<<errorMessage<<std::endl;
    return false;
}

void testFoo() {
    int size = 6;
    int* arr = new int[size] {1,2,51,64,36,0};
    fooTest(arr, size, 64,"ok", "error");

    int* arr2 = new int[size] {0};
    fooTest(arr2,0,0,"ok","error");

    delete [] arr;
    delete [] arr2;
}

int main() {
    testFoo();
}