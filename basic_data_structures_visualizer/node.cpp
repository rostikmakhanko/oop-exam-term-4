#include "node.h"

Node::Node()
{
    next=nullptr;
    value=0;
}

Node::Node(int value)
{
    next=nullptr;
    this->value=value;
}
