#pragma once
#include <stdexcept>
#include <iostream>


class Queue
{
    struct Node
    {
        int data;
        Node* next;

        Node()
        {
            data = 0;
            next = nullptr;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }

        ~Node()
        {
            delete next;
        }
    };
    Node* first;
    Node* last;

public:
    Queue();
    ~Queue();
    void push(int);
    int pop();
};

Queue::Queue()
{
    first = nullptr;
    last = nullptr;
}

Queue::~Queue()
{
    delete first;
}

void Queue::push(int data)
{
    if(first == nullptr)
    {
        first = new Node {data, nullptr};
        last = first;
    }
    else
    {
        Node* newNode = new Node {data, first};
        first = newNode;
    }
}

int Queue::pop()
{
    if(first == nullptr){
        throw std::out_of_range("Cannot pop empty queue");
    } 

    if(first == last)
    {
        int returnData = last->data;
        delete first;
        first = nullptr;
        last = nullptr;
        return returnData;
    }

    Node* current = first;
    while (current->next != last)
    {
        current = current->next;
    }
    
    int returnData = last->data;

    delete last;
    
    last = current;
    last->next = nullptr;

    return returnData;
}