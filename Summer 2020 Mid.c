#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

int main()
{  node *Head , *Second , *Third ,*Fourth ,*Fifth;

    Head =(node*)malloc(sizeof(node));
    Second =(node*)malloc(sizeof(node));
    Third =(node*)malloc(sizeof(node));
    Fourth =(node*)malloc(sizeof(node));
    Fifth =(node*)malloc(sizeof(node));

    Head->data =1;
    Head->next = Second;

    Second->data =3;
    Second->next = Third;

    Third->data =2;
    Third->next = Fourth;

    Fourth->data =20;
    Fourth->next = Fifth;

    Fifth->data =30;
    Fifth->next = NULL;

    node *value = Head;
        while(value !=NULL)
    {
        printf("%d-> ",value->data);
        value =value->next;
    }
    return 0;
}

