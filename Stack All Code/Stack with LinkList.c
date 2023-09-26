#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *top = NULL;

void push(int value) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void display() {
    node *temp;
    temp = top;

    if (temp == NULL) {
        printf("Stack is EMPTY \n");
    } else {
        printf("Stack: \n");
        while (temp != NULL) {
            printf("|%d| \n", temp->data);
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
        printf("Popped: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

int main() {
    push(11);
    push(22);
    push(33);
    push(44);

    display();
    peek();
    pop();
    display();

    return 0;
}
