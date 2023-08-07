#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
struct node *prev;
char data;
struct node *next;
}; 
typedef struct node node; 
int main() 
{ 
    node *n1 , *n2 , *n3 ,*n4;

    n1 =(node*)malloc(sizeof(node));
    n2 =(node*)malloc(sizeof(node));
    n3 =(node*)malloc(sizeof(node));
    n4 =(node*)malloc(sizeof(node));

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
 
    printf(" Link list Create successfully !!\n"); 
    printf("%c-> ",n1->data); 
    printf("%c-> ",n2->data); 
    printf("%c-> ",n3->data); 
    printf("%c-> ",n4->data); 
    return 0; 
}
