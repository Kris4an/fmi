#include <iostream>
#include <algorithm>
#include <array>

const int  MAX_SIZE = 256;
void printArray(int arr[], int size){
    for(int i = 0; i < size; ++i) std::cout<<arr[i]<<' ';
    std::cout<<'\n';
}
bool zad3(int arr[], int size){
    for(int i = 0; i < size/2; ++i){
        if(arr[i] != arr[size-i-1]) return false;
    }
    return true;
}
int zad4(int arr[], int size){
    int min = arr[1], max = arr[1];
    for(int i = 1; i < size; ++i){
        if(min>arr[i]) min = arr[i];
        if(max<arr[i]) max = arr[i];
    }
    return max-min;
}
int* zad5_bubbleSort(int arr[], int size){
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            if(arr[i]>arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}
int* zad6(int arr[], int& size){
    std::sort(arr, arr+size);
    int res[size];
    int i = 0, j = 0;
    while(i<size){
        if(arr[i] == arr[i+1]) ++i;
        else {
            res[j] = arr[i];
            ++j;
            ++i;
        }
    }
    for(int k = 0; k < j; ++k){
        arr[k] = res[k];
    }
    size = j;
    return arr;
}
int* zad7(int arr[], int& size, int n, int el){
    if(n>size || n<0) throw std::runtime_error("Invalid index");
    if(size == MAX_SIZE) throw std::runtime_error("Not enough space!");
    for(int i = size; i > n; --i){
        arr[i] = arr[i-1];
    }
    ++size;
    arr[n] = el;
    return arr;
}
int* zad8(int arr[], int& size, int n){
    if(n>size || n<0) throw std::runtime_error("Invalid index");
    for(int i = n+1; i < size; ++i){
        arr[i-1] = arr[i];
    }
    --size;
    return arr;
}
void zad9(char str[]){
    int res[26] = {0};
    for(int i = 0; str[i]!='\0'; ++i){
        ++res[str[i]-'a'];
    }
    for(int i = 0; i < 26; i++){
        if(res[i]!=0) std::cout<<(char)(i+'a')<<" = "<<res[i]<<'\n';
    }
}
int* mergeSort(int*  arr, int size){
    if(size == 0) return nullptr;
    if(size == 1) return arr;
    if(size == 2){
        if(arr[0] > arr[1]) std::swap(arr[0], arr[1]);
        return arr;
    }
    int* p = mergeSort(arr, size/2);
    int* g = mergeSort(arr+size/2, size-size/2);
    int* left = new int[size/2];
    std::copy(p, p+size/2, left);
    int* right = new int[size-size/2];
    std::copy(g, g+size-size/2, right);
    for(int i = 0, j = 0, s = 0; i+j<size; ++s){
        if((left[i] < right[j] && i<size/2) || j>=size-size/2){
            arr[s] = left[i];
            ++i;
        }
        else{
            arr[s] = right[j];
            ++j;
        }
    }
    delete [] left;
    delete [] right;
    return arr;
}
int* MS(int* A, int size){
    if(size == 0) return nullptr;
    if(size == 1) return A;
    if(size == 2){
        if(A[1] < A[0]){
            std::swap(A[1], A[0]);
        }
        return A;
    }
    int lSize = size/2;
    int rSize = size - size/2;
    int* L = MS(A, lSize);
    int* R = MS(A+size/2, rSize);

    int* newArray = new int[size];
    int i = 0, j = 0, n = 0;
    while(i<lSize && j<rSize){
        if(L[i] <= R[j]){
            newArray[n] = L[i];
            ++i;
        }
        else{
            newArray[n] = R[j];
            ++j;
        }
    }
    int restCnt;
    int* restArr;
    if(i == lSize){
        restCnt = j;
        restArr = R;
    }
    else{
        restCnt = i;
        restArr = L;
    }
    for(;n<size;++n, ++restCnt){
        newArray[n] = restArr[restCnt];
    }
    return newArray;
}
int main(){
    int size = 30;
    int arr[MAX_SIZE] = {78,13,44,93,-9,-8,23,99,-43,11,68,-14,9,-100,32,45,34,234,52,-35,2,23,-42,-23,23,2,53,876,9,8,0,77,-346,345,-5};
    
    int* d = mergeSort(arr, size);
    //int* d = zad5_bubbleSort(arr, size);
    printArray(d,size);
    return 0;
}