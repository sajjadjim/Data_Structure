#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *head;

void createnode(int n);
void display();
void insert_beg();
void insert_end();
void insert_middle(int position);
void delete_first();
void delete_middle(int position);
void delete_last();

void createnode(int n) {
    node *newnode, *temp;
    int i;
    head = (node *)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    head->next = NULL;
    printf("\nEnter data for Node 1: ");
    scanf("%d", &head->data);
    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed.");
            exit(1);
        }
        printf("\nEnter data for Node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void insert_beg() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    printf("\nEnter data for beginning node: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insert_middle(int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    node *newnode, *temp;
    temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    printf("Enter data at MIDDLE position: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_end() {
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    printf("\nEnter data for last node: ");
    scanf("%d", &newnode->data);
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void delete_first() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp;
    temp = head;
    head = temp->next;
    free(temp);
}

void delete_middle(int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or empty list.\n");
        return;
    }
    node *current, *temp, *prev;
    temp = head;
    for (int i = 1; i < position; i++) {
        prev = temp;
        current = temp->next;
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    prev->next = current->next;
    free(current);
}

void delete_last() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp, *prev;
    temp = head;
    prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void display() {
    node *temp;
    temp = head;
    if (temp == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nYou have Successfully created the following linked list:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("\nEnter total number of nodes: ");
    scanf("%d", &n);
    createnode(n);
    display();

    printf("\nInserting new node at the beginning...\n");
    insert_beg();
    display();

    int pos;
    printf("\nInserting the value at the MIDDLE position......\n");
    printf("Enter the position number: ");
    scanf("%d", &pos);
    insert_middle(pos);
    display();

    printf("\nInserting new node at the end...\n");
    insert_end();
    display();

    // Delete Node First
    delete_first();
    display();

    // Delete Middle / Any Node
    printf("\nDeleting a node from the middle...\n");
    printf("Enter the position number to delete: ");
    scanf("%d", &pos);
    delete_middle(pos);
    display();

    // Delete Last Node
    delete_last();
    display();

    return 0;
}
