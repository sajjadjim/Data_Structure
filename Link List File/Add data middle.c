#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
typedef struct node node;
void nodeDisplay();
void insert_middle(int pos);

void createNode(int n)
{
    head =(node*)malloc(sizeof(node));
    printf("Enter node 1 data :");
    scanf("%d",&head->data);

    node *newnode ,* temp;
    temp = head;
    for(int i=2 ; i<=n ; i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter node %d data :",i);
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        temp->next =newnode;
        temp = temp->next;
    }
}

void insert_middle(int pos){
  node *newnode, *prev ,*current ,*temp;
  newnode=(node*)malloc(sizeof(node));
  printf("Enter %d node data :",pos);
  scanf("%d",&newnode->data);
  temp = head;
  for(int i=1; i<pos ;i++)
  {
      prev = temp;
      current = temp->next;
      temp = temp->next;
  }
  prev->next =newnode;
  newnode->next =current;
}
/*
void insert_middle(int pos){
    struct node *newnode, *temp;
    temp=head;
    newnode = (node*) malloc(sizeof(node));
    printf("Enter %d node data :",pos);
    scanf("%d",&newnode->data);
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
} */


//Display the node value ~~
void nodeDisplay(){
    node *value;
    int i=1;
    value= head;
    while(value !=NULL)
    {
        printf("Node %d data ->%d",i,value->data);
        value = value->next;
        i++;
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter number of node :");
    scanf("%d",&n);
    createNode(n);
    printf("\nLinkList Create successfully Done !!!\n");
    nodeDisplay();

    //New node add middle
    printf("\nEnter position number :");
    int pos;
    scanf("%d",&pos);
    insert_middle(pos);
    nodeDisplay();
    return 0;
}
