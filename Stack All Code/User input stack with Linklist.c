#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *top = NULL;

void push(int n) {
     node *newnode;
     int value;

    for(int i=0 ;i < n ; i++)
    {
    printf("Enter %d data : ",i+1);
    scanf("%d",&value);

    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    }
}

void display() {
    node *temp;
    temp = top;

    if (temp == NULL) {
        printf("\n \t Stack is EMPTY \n");
    } else {
        printf("\n Stack : \n");
        while (temp != NULL) {
            printf("\t |%d| \n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (top == NULL) {
        printf("TOP is NULL\n");
    } else {
        printf("TOP = |%d|\n", top->data);
    }
}

void pop() {
    node *temp;
    temp = top;
    if (temp == NULL) {
        printf("UNDERFLOW stack...\n");
    } else {
        printf("Pop Value : %d \n", temp->data);
        top = top->next;
        free(temp);
    }
}

int main() {
int n;
printf("How many data input in stack :");
scanf("%d",&n);
push(n);
display();
peek();
pop();
display();
return 0;
}

