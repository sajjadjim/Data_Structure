#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node *prev;
char data;
struct node *next;
};
typedef struct node head;
int main()
{
    node *n1 , *n2 , *n3 ,*n4;

    n1 =(head*)malloc(sizeof(n1));
    n2 =(head*)malloc(sizeof(n2));
    n3 =(head*)malloc(sizeof(n3));
    n4 =(head*)malloc(sizeof(n4));

    n1->data ='A';
    n1->next = n2;

    n2->data ='B';
    n2->next =n3;
    n3->prev =n2;

    n3->data ='B';
    n3->next =n4;
    n3->prev =n2;

    n4->data ='D';
    n4->next =NULL;
    n4->prev =n3;

    cout << n1->data << endl;

    cout << n2->data << endl;

    cout << n3->data << endl;

    cout << n4->data << endl;
}
