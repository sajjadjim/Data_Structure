#include<stdio.h>
#include<stdlib.h>
struct node {
    int n;
    char o[10];
    struct node *p;

};
typedef struct node node ;
int main()
{
  node  *node1 , *node2;
node1=(node*)malloc(sizeof(node));
node2=(node*)malloc(sizeof(node));

    node1->n = 18;
    strcpy(node1->o, "Head"); // Use strcpy to copy the string
    node1->p = node2;

    node2->n = 13;
    strcpy(node2->o, "Tail"); // Use strcpy to copy the string
    node2->p = NULL;

printf(" Node 1 Data : %d\n",node1->n);
printf(" Node 1 Data : %s\n",node1->o);

printf(" Node 2 Data : %d\n",node2->n);
printf(" Node 2 Data : %s\n",node1->o);

return 0;
}
