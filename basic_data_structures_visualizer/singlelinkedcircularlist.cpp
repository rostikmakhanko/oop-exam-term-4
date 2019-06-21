#include "singlelinkedcircularlist.h"

SingleLinkedCircularList::SingleLinkedCircularList()
{
    head=nullptr;
    tail=head;
    size=0;
}

SingleLinkedCircularList::SingleLinkedCircularList(int value)
{
    Node *new_node=new Node(value);
    new_node->next=new_node;
    head=new_node;
    tail=head;
    size=1;
}

void SingleLinkedCircularList::push_back(int value)
{
    if (size==0)
    {
        Node *new_node=new Node(value);
        new_node->next=new_node;
        head=new_node;
        tail=new_node;
    }
    else
    {
        Node *new_node=new Node(value);
        tail->next=new_node;
        new_node->next=head;
        tail=new_node;
    }
    size++;
}

void SingleLinkedCircularList::push_front(int value)
{
    if (size==0)
    {
        Node *new_node=new Node(value);
        new_node->next=new_node;
        head=new_node;
        tail=new_node;
    }
    else
    {
        Node *new_node=new Node(value);
        new_node->next=head;
        head=new_node;
        tail->next=head;
    }
    size++;
}

void SingleLinkedCircularList::insert(int value, int position)
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
        Node *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        Node *new_node=new Node(value);
        new_node->next=cur_node->next;
        cur_node->next=new_node;
        size++;
    }
}

void SingleLinkedCircularList::pop_back()
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
        Node *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        cur_node->next=head;
        tail=cur_node;
    }
    size--;
}

void SingleLinkedCircularList::pop_front()
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
        Node *cur_node=head;
        cur_node=cur_node->next;
        delete head;
        head=cur_node;
        tail->next=head;
    }
    size--;
}

void SingleLinkedCircularList::erase(int position)
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
        Node *cur_node=head;
        while (steps--)
        {
            cur_node=cur_node->next;
        }
        Node *delete_node=cur_node->next;//node which we need to delete
        cur_node->next=cur_node->next->next;
        delete delete_node;
        size--;
    }
}

void SingleLinkedCircularList::clear()
{
    while (size>0)
    {
        pop_back();
    }
}

QString SingleLinkedCircularList::to_string()
{
    QString ans="";
    if (size==0) return ans;
    Node *cur_node=head;
    ans=QString::number(head->value);
    cur_node=cur_node->next;
    while (cur_node!=head)
    {
        ans+=" "+QString::number(cur_node->value);
        cur_node=cur_node->next;
    }
    return ans;
}
