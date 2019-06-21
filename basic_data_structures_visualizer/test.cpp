#include "test.h"
#include "node.h"
#include "singlelinkedcircularlist.h"
#include <iostream>

using std::cout;

Test::Test()
{

}

void Test::start()
{
   SingleLinkedCircularList<int> list;
   list.push_back(5);
   if (list.head->value!=5)
   {
       cout<<"fail";
   }
}
