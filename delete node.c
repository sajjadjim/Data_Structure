#include <stdio.h>
#include <stdlib.h>5
struct node{
    int data;
    struct node *next;
}*head;
typedef struct node node;
// Function prototypes
void createlist(int n);
void displaylist();
void searchinginlist(int searchitem);

void createlist(int n){
    struct node *newnode, *temp;
    head = (struct node*) malloc(sizeof(struct node));
    printf("Enter the value of the first node :");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for(int i = 1; i < n; i++){
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter node-%d data :", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;

    }
}

void displaylist(){
    struct node *temp;
    temp = head;
    printf("Display list\n");
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void delete_node()
{
    int pos ,i;
    node *current,*temp,*prev;
    printf("Enter the node number which you want to delete :");
    scanf("%d",&pos);
     temp = head;
    for(int i=1 ; i<pos ; i++)
    {
     prev = temp;
     current = temp->next;
     temp= current;
    }
    prev->next = current->next;
    free(current);

}

int main(){
    int n, item, pos;
    printf("Enter the number of nodes in the list :");
    scanf("%d", &n);
    createlist(n);
    displaylist();
    delete_node();
    //After the delete Node
    displaylist();
    return 0;
}
