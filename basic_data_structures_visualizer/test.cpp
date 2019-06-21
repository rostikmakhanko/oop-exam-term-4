#include "test.h"
#include "node.h"
#include "singlelinkedcircularlist.h"
#include "singlelinkedcircularlist.tpp"
#include <iostream>
#include <QVector>
#include "organization.h"

using std::cout;
using std::endl;

Test::Test()
{

}

void Test::start()
{
   SingleLinkedCircularList<int> list;
   list.push_back(5);
   QVector<int> x={5};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   for (int i=0;i<6;i++)
       list.push_back(i);
   x={5,0,1,2,3,4,5};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   list.insert(10,3);
   x={5,0,1,10,2,3,4,5};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   list.erase(1);
   x={5,1,10,2,3,4,5};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   list.pop_front();
   x={1,10,2,3,4,5};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   list.clear();
   x={};
   if (list.to_vector()!=x)
   {
       cout<<"fail";
       exit(0);
   }

   cout<<"passed"<<endl;
}
