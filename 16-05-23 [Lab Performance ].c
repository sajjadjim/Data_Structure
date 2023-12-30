#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node  *next;
} *head;
typedef struct node node;
void createList(int n);

void createList(int n) {
    node *newnode, *temp;
    head = (node*)malloc(sizeof(node));
    printf("Enter the data for the first node: ");
    scanf("%d", &head->data);
    head->next = head;
    temp = head;

    for (int i = 2; i <= n; i++)
        {
        newnode = (node*)malloc(sizeof(node));
        printf("Enter data for node %d : ", i);
        scanf("%d",&newnode->data);
        newnode->next = head;
        temp->next = newnode;
        temp = temp->next;
    }
}


void insert_First()
{
    int newData;
    printf("\nEnter data at the First node: ");
    scanf("%d", &newData);

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data =newData;
    newNode->next = head;

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayNode() {
   if(head == NULL)
   {
       printf("Linklist NULL !!! ");
   }

   else
    {
    struct node* temp = head;
    printf("\n");
       do{
            printf("Current Address: %p  DATA: %d \t", temp, temp->data);
            printf("\nNext Address: %p ",temp->next);
            temp = temp->next;
        }
        while(temp != head);
        printf("\n");
   }
}

int main() {
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    displayNode();


    insert_First();

    printf("\nData after inserting at the First !!\n");
    displayNode();

    int newData;
    printf("\nEnter data end of the Node : ");
    scanf("%d", &newData);
    insertAtEnd(newData);

    printf("\nData after inserting at the end !!!\n");
    displayNode();

    return 0;
}
