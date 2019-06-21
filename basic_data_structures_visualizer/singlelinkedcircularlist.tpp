#include "singlelinkedcircularlist.h"
#include "node.tpp"

template <typename T>
SingleLinkedCircularList<T>::SingleLinkedCircularList()
{
    head=nullptr;
    tail=head;
    size=0;
}

template <typename T>
SingleLinkedCircularList<T>::SingleLinkedCircularList(T value)
{
    Node<T> *new_node=new Node<T>(value);
    new_node->next=new_node;
    head=new_node;
    tail=head;
    size=1;
}

template <typename T>
void SingleLinkedCircularList<T>::push_back(T value)
{
    if (size==0)
    {
        Node<T> *new_node=new Node<T>(value);
        new_node->next=new_node;
        head=new_node;
        tail=new_node;
    }
    else
    {
        Node<T> *new_node=new Node<T>(value);
        tail->next=new_node;
        new_node->next=head;
        tail=new_node;
    }
    size++;
}

template <typename T>
void SingleLinkedCircularList<T>::push_front(T value)
{
    if (size==0)
    {
        Node<T> *new_node=new Node<T>(value);
        new_node->next=new_node;
        head=new_node;
        tail=new_node;
    }
    else
    {
        Node<T> *new_node=new Node<T>(value);
        new_node->next=head;
        head=new_node;
        tail->next=head;
    }
    size++;
}

template <typename T>
void SingleLinkedCircularList<T>::insert(T value, int position)
{
    if (position<0||position>size) return;
    if (position==size)
    {
        push_back(value);
    }
    else if (position==0)
    {
        push_front(value);
    }
    else
    {
        int steps=position-1;
        Node<T> *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        Node<T> *new_node=new Node<T>(value);
        new_node->next=cur_node->next;
        cur_node->next=new_node;
        size++;
    }
}

template <typename T>
void SingleLinkedCircularList<T>::pop_back()
{
    if (size==0) return;
    if (size==1)
    {
        delete tail;
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        delete tail;
        int steps=size-2;
        Node<T> *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        cur_node->next=head;
        tail=cur_node;
    }
    size--;
}

template <typename T>
void SingleLinkedCircularList<T>::pop_front()
{
    if (size==0) return;
    if (size==1)
    {
        delete head;
        head=nullptr;
        tail=nullptr;
    }
    else
    {
        Node<T> *cur_node=head;
        cur_node=cur_node->next;
        delete head;
        head=cur_node;
        tail->next=head;
    }
    size--;
}

template <typename T>
void SingleLinkedCircularList<T>::erase(int position)
{
    if (position<0||position>=size) return;
    if (position==0)
    {
        pop_front();
    }
    else if (position==size-1)
    {
        pop_back();
    }
    else
    {
        int steps=position-1;
        Node<T> *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        Node<T> *delete_node=cur_node->next;//node which we need to delete
        cur_node->next=cur_node->next->next;
        delete delete_node;
        size--;
    }
}

template <typename T>
void SingleLinkedCircularList<T>::clear()
{
    while (size>0)
    {
        pop_back();
    }
}

template <typename T>
QString SingleLinkedCircularList<T>::to_string()
{
    QString ans="";
    if (size==0) return ans;
    Node<T> *cur_node=head;
    ans=QString::number(head->value);
    cur_node=cur_node->next;
    while (cur_node!=head)
    {
        ans+=" "+QString::number(cur_node->value);
        cur_node=cur_node->next;
    }
    return ans;
}
