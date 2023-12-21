#include<stdio.h>
#include<stdlib.h>
  
struct node {
    int StudentID;
    float Marks;
    char Section;
    struct node *next;
}*head;
typedef struct node node;
void createNode(int n);
void nodeDisplay();

void createNode(int n) {
    head = (node*)malloc(sizeof(node));
    printf("Enter Student 1 StudentID: ");
    scanf("%d", &head->StudentID);
    printf("Enter Student 1 Marks: ");
    scanf("%f", &head->Marks);
    printf("Enter Student 1 Section: ");
    getchar();
    scanf("%c", &head->Section);
    printf("\n");
    head->next = NULL;

    node *newnode, *temp;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newnode = (node*)malloc(sizeof(node));
        printf("Enter Student %d StudentID: ", i);
        scanf("%d", &newnode->StudentID);
        printf("Enter Student %d Marks: ", i);
        scanf("%f", &newnode->Marks);
        printf("Enter Student %d Section: ", i);
        getchar();
        scanf("%c", &newnode->Section);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
        printf("\n");
    }
}

void nodeDisplay() {
    node *value;
    int i = 1;
    value = head;
    while (value != NULL) {
        printf("Student %d StudentID -> %d\n", i, value->StudentID);
        printf("Marks -> %.2f\n", value->Marks);
        printf("Section -> %c\n", value->Section);
        value = value->next;
        i++;
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter number of studens : ");
    scanf("%d", &n);
    createNode(n);
    printf("\nLinkedList created successfully!\n");
    nodeDisplay();
    return 0;
    
}
