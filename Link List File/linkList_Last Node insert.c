#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

typedef struct node nodal;

void createnode(int n);
void displayList();
void insert_node_last();

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createnode(n);
    printf("\nLinked list created successfully!\n");

    printf("The linked list elements are: ");
    displayList();

    insert_node_last();  // Here call the LastNode add function

    printf("\nLinked list last node insert successfully!\n");
    printf("The linked list elements are: ");
    displayList();       // Again print the value
    return 0;
}

void createnode(int n)
{
    head = (nodal*)malloc(sizeof(nodal));


    printf("Enter data for node 1: ");
    scanf("%d", &head->data);

    head->next = NULL;

    int i;
    nodal *newnode, *temp;
    temp = head;

    for (i = 2; i <= n; i++)
    {
        newnode = (nodal*)malloc(sizeof(nodal));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void insert_node_last()
{
   nodal *newnodeLast ,*temp;
   temp = head;  // Full node insert to store the temp , then it should be connect to last add  new node process
   newnodeLast =(nodal*)malloc(sizeof(nodal));
   printf("\nInsert last node Data again to add :");
   scanf("%d",&newnodeLast->data);

   while(temp->next != NULL)    // This loop will be continue , when the temp last node not found NULL
   {
       temp = temp->next;
   }
   temp->next = newnodeLast;  // Here temp full node connected , at last create newNode
   newnodeLast->next=NULL;
}

void displayList()
{
    nodal *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
