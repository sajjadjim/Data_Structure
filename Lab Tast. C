#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
}*head;
typedef struct node node;
void create_List(int n);
void insertAtBeginning(int data);
void deleteAtBeginning();

void create_List(int n)
{
    struct node* newnode, * temp;
    head = (node*)malloc(sizeof(node));
    printf("Enter the data for the first node: ");
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Input data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void insertAtBeginning(int data)
{
    node *newnode =(node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}
void insertAtMiddle(int position, int data)
{
     node *newNode =(node*)malloc(sizeof(node));
    newNode->data = data;

    node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning()
{

    node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

void Display()
{
        node *temp = head;
        while (temp!= NULL)
        {
            printf("DATA: %d\n",temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }

int main() {
    int n;
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    create_List(n);
    printf("\nData entered in the doubly linked list:\n");
    Display();

    int b_data;
    printf("Enter data : ");
    scanf("%d",&b_data);
    insertAtBeginning(b_data);
    Display();

    int position;
    int data;
    printf("Enter middle position : ");
    scanf("%d",&position);
    printf("Enter Middle position data : ");
    scanf("%d",&data);
    insertAtMiddle(position,data);
    Display();

    printf("\n \n After Delete First position !!! \n");
    deleteAtBeginning();
    Display();



    return 0;
}
