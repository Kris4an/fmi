#include <iostream>

int RETURN_COUNT = 0;

bool isEven(int number){
    return number%2==0;
}
bool isOdd(int number){
    return number%2==1;
}
int foo(int number){
    return number*5;
}

int* filterArray(int* A, int size, bool(*filter)(int)){
    int returnCnt = 0;
    int* result = new int[size];
    for(int i =0; i < size; ++i){
        if(filter(A[i])){
            result[returnCnt] = A[i];
            ++returnCnt;
        }
    }
    int* sizedResult = new int[returnCnt];
    for(int i = 0; i < returnCnt; ++i) sizedResult[i] = result[i];
    RETURN_COUNT = returnCnt;
    delete[] result;
    return sizedResult;
}

int* mapArray(int* A, int size, int (*transformFunc)(int)){
    int* resultArr = new int[size];
    for(int i = 0; i < size; ++i){
        resultArr[i] = transformFunc(A[i]);
    }
    return resultArr;
}

int main(){
    int size = 5;
    int* A = new int[size];
    for(int i = 0; i < size; ++i){
        std::cin>>A[i];
    }

    std::cout<<'\n';
    A = mapArray(A, size, *foo);
    for(int i = 0; i < size; ++i){
        std::cout<<A[i]<<'\n';
    }

    std::cout<<'\n';
    A = filterArray(A, size, *isOdd);
    for(int i = 0; i < RETURN_COUNT; ++i){
        std::cout<<A[i]<<'\n';
    }

    delete[] A;

    return 0;
};