#include<iostream>
#include<stdlib.h>

using namespace std;
 struct node {
 int x ;
 float y;
 char z;
 struct node *next;   // self refarencial pointer
 };
 typedef struct node head;
 int main()
{
  head *baby , *fish ,*cat;
  baby =(head*)malloc(sizeof(head));   // Memory Address create
  fish =(head*)malloc(sizeof(head));   // Memory Address create
  cat =(head*)malloc(sizeof(head));   // Memory Address create

  baby->x =7; baby->y =1.5; baby->z = 'A';
  baby->next=fish;

  fish->x = 10; fish->y =3.5; fish->z = 'B';
  fish->next=cat;

  cat->x = 13; cat->y =5.5; cat->z = 'C';
  cat->next=NULL;

    cout <<"Print value "<< baby->x << endl;
    cout <<"Print value "<< baby->y << endl;
    cout <<"Print value "<< baby->z << endl<<endl;

    cout <<"Print value "<< fish->x << endl;
    cout <<"Print value "<< fish->y << endl;
    cout <<"Print value "<< fish->z << endl<<endl;

    cout <<"Print value "<< cat->x << endl;
    cout <<"Print value "<< cat->y << endl;
    cout <<"Print value "<< cat->z << endl;

 return 0;
}

