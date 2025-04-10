#include <iostream>

struct dynamic_array
{
    int *arr;
    size_t size;
    size_t capacity;

    dynamic_array()
    {
        capacity = size = 0;
        arr = nullptr;
    }

    dynamic_array(size_t capacity)
    {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    ~dynamic_array()
    {
        delete[] arr;
    }

    void da_append(int value)
    {
        if(size < capacity)
        {
            arr[size++] = value;
        }
    }
};

int main()
{
    dynamic_array x(100);
}
