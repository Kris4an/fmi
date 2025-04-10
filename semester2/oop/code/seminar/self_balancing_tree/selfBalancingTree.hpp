#pragma once
#include <iostream>
#include <cmath>
#include <stack>

class myTree
{
    struct Node
    {
        Node *left;
        Node *right;
        int value;

        Node()
        {
            left = nullptr;
            right = nullptr;
            value = 0;
        }
        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
        Node(const Node &other)
        {
            delete left;
            delete right;

            value = other.value;
            left = other.left;
            right = other.right;
        }

        ~Node()
        {
            delete left;
            delete right;
        }
    };
    struct myArr
    {
        int *arr;
        size_t size;

        myArr()
        {
            arr = nullptr;
            size = 0;
        }
        myArr(int *a, size_t s)
        {
            arr = a;
            size = s;
        }

        ~myArr()
        {
            delete [] arr;
        }
    };

    Node *root;
    int size;

    int subTreeHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node, 0);
    }
    int getHeight(Node *node, int height)
    {
        int lHeight = 0, rHeight = 0;
        if (node->left != nullptr)
        {
            lHeight = getHeight(node->left, height + 1);
        }
        if (node->right != nullptr)
        {
            rHeight = getHeight(node->right, height + 1);
        }

        return (lHeight > rHeight) ? lHeight : rHeight;
    }
    int* toArr(Node *node)
    {
        int *arr = new int[size];
        int index = 0;

        std::stack<Node *> st;
        st.push(node);

        while (st.top()->left != nullptr)
        {
            st.push(st.top()->left);
        }

        while (!st.empty())
        {
            arr[index] = st.top()->value;
            ++index;
            if (st.top()->right != nullptr)
            {
                myArr ma = getSubTreeArr(st.top()->right);

                std::copy(ma.arr, ma.arr + ma.size, arr + index);
                index += ma.size;
            }

            st.pop();
        }

        return arr;
    }
    myArr getSubTreeArr(Node *node)
    {
        int *arr = new int[size];
        size_t index = 0;

        std::stack<Node *> st;
        st.push(node);

        while (st.top()->left != nullptr)
        {
            st.push(st.top()->left);
        }

        while (!st.empty())
        {
            arr[index] = st.top()->value;
            ++index;

            if (st.top()->right != nullptr)
            {
                myArr mArr = getSubTreeArr(st.top()->right);

                std::copy(mArr.arr, mArr.arr + mArr.size, arr + index);
                index += mArr.size;
            }

            st.pop();
        }

        myArr ma(arr, index);
        return ma;
    }

public:
    myTree()
    {
        root = nullptr;
        size = 0;
    }
    ~myTree()
    {
        delete root;
    }

    void add(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
            ++size;
            return;
        }

        Node *current = root;
        while (true)
        {
            if (current->value > value)
            {
                if (current->left == nullptr)
                {
                    current->left = new Node(value);
                    break;
                }
                current = current->left;
                continue;
            }
            if (current->value < value)
            {
                if (current->right == nullptr)
                {
                    current->right = new Node(value);
                    break;
                }
                current = current->right;
                continue;
            }

            if (current->value == value)
            {
                std::cerr << "This value is already added";
                return;
            }
        }

        ++size;
        //balance();
    }
    void remove(int);

    void balance()
    {
        int lHeight = subTreeHeight(root->left);
        int rHeight = subTreeHeight(root->right);

        if (abs(lHeight - rHeight) <= 1)
        {
            return;
        }

        int* arr = toArr(root);

        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }

        delete [] arr;
    }
};