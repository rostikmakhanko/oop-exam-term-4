#include "node.h"

template <typename T>
Node<T>::Node()
{
    next=nullptr;
    value=0;
}

template <typename T>
Node<T>::Node(T value)
{
    next=nullptr;
    this->value=value;
}
