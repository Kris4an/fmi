#include <stdexcept>
#include "library.h"

namespace fmi {
dynamic_array::dynamic_array() : m_data(nullptr), m_allocated(0)//myObj(x,y) -> right constructer
{
    //myObj.f(); -> default constructer for myObj
}
dynamic_array::dynamic_array(size_t size)
{
    m_data = new int[size];
    m_allocated = size;
}
// size_t dynamic_array::capacity() const 
// {
//     return m_allocated;
// }
size_t dynamic_array::size() const 
{
    return m_allocated;
}

int& dynamic_array::at(size_t index)
{
    if(index >= m_allocated) throw std::out_of_range("Tuk ne e informaciq");
    return m_data[index];
}

} //namespace fmibv  