#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node();
    Node(T value);
    ~Node(){}
    Node *next;
    T value;
};

#endif // NODE_H
