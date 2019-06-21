#ifndef SINGLELINKEDCIRCULARLIST_H
#define SINGLELINKEDCIRCULARLIST_H
#include "node.h"
#include <QString>


class SingleLinkedCircularList
{
public:
    SingleLinkedCircularList();
    SingleLinkedCircularList(int value);
    ~SingleLinkedCircularList();

public:
    Node *head,*tail;
    int size;

public:

    int get_size()
    {
        return size;
    }

    void push_back(int value);

    void push_front(int value);

    void insert(int value,int position);

    void pop_back();

    void pop_front();

    void erase(int position);

    void clear();

    QString to_string();

};

#endif // SINGLELINKEDCIRCULARLIST_H
