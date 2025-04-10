#include <iostream>
#include "queue.hpp"

int main()
{
    Queue q = Queue();

    for(int i = 0; i < 5; ++i)
    {
        q.push(i);
    }

    for (int i = 0; i < 6; ++i)
    {
        std::cout << q.pop() << " ";
    }
    

    return 0;
}