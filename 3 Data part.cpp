#include<iostream>
#include<stdlib.h>

using namespace std;

 struct node {

 int x ;
 float y;
 char z;

 struct node *next;  // self refefarencial pointer creation
 };
 typedef struct node head;

 int main()
{
  head *node1 , * node2;
  node1 =(head*)malloc(sizeof(head));   // Memory Address create
  node2 =(head*)malloc(sizeof(head));   // Memory Address create
  node1-> x =6;
  node1->y =64.99;
  node1->z = 'Aim';
  node1->next=node2;

  node2-> x = 9;
  node2->y =3.19;
  node2->z = 'Blim';
  node2->next=NULL;

    cout <<"Print value "<< node1->x << endl;
    cout <<"Print value "<< node1->y << endl;
    cout <<"Print value "<< node1->z << endl<<endl;

    cout <<"Print value "<< node2->x << endl;
    cout <<"Print value "<< node2->y << endl;
    cout <<"Print value "<< node2->z << endl;

 return 0;
}
