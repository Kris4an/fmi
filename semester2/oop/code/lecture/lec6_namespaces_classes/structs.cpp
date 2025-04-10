#include <iostream>

struct dynamic_array {
    int* arr; //member variable
    size_t capacity;
    size_t size;
};

void da_initialize(dynamic_array* instance, size_t capacity)
{
    instance->capacity = capacity;
    instance->size = 0;
    instance->arr = new int [capacity];
}

void da_release(dynamic_array* instance)
{
    delete [] instance->arr;
}

int by_copy(int x)
{
    x++;
    return x;
}
int by_ref(int& x)
{
    x++;
    return x;
}
int by_ptr(int* x)
{
    (*x)++;
    return *x;
}

int main()
{
    dynamic_array x;

    // x.capacity = 100;
    // x.arr = new int[x.capacity];
    da_initialize(&x, 100);

    //   ptr         var, ref
    // [    ] ----> [ 42 ]
    int var = 42;
    int* ptr = &var;
    int& ref = var;

    std::cout<<ref<<"\n";

    int var2 = 12;
    ptr = &var2;
    ref = var2; //не може :(

    std::cout<<ref;
}