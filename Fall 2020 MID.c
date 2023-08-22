#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;
typedef struct node nodal;

void createnode(int n);
void displayList();
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createnode(n);
    printf("\nLinked list created successfully!\n");

    printf("The linked list elements are: ");
    displayList();
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

void displayList()
{
    nodal *current = head;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
}
