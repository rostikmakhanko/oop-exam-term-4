#ifndef SINGLELINKEDCIRCULARLIST_H
#define SINGLELINKEDCIRCULARLIST_H
#include "node.h"
#include <QString>

template <typename T>
class SingleLinkedCircularList
{
public:
    SingleLinkedCircularList();
    SingleLinkedCircularList(T value);
    ~SingleLinkedCircularList(){};

public:
    Node<T> *head,*tail;
    int size;

public:

    int get_size()
    {
        return size;
    }

    void push_back(T value);

    void push_front(T value);

    void insert(T value,int position);

    void pop_back();

    void pop_front();

    void erase(int position);

    void clear();

    QString to_string();

};

#endif // SINGLELINKEDCIRCULARLIST_H
