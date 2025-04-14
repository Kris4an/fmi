#pragma once
#include <iostream>
#include <stdexcept>

namespace fmi
{
class dynamic_array
{
    int *m_data;
    size_t m_allocated;
    //size_t m_used;

public:
    dynamic_array();
    dynamic_array(size_t size);
    //size_t capacity() const;
    size_t size() const;
    int& at(size_t);
    void f(int, int);
};

} //namespace fmi