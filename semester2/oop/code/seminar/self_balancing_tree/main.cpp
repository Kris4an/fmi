#include <iostream>
#include "selfBalancingTree.hpp"

int main()
{
    myTree t;

    t.add(5);
    t.add(8);
    t.add(3);
    t.add(1);
    t.add(9);
    t.add(6);
    
    t.balance();
}