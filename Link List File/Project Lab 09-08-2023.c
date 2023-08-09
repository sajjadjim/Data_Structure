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
void new_nodeFirst();
void insert_end();
void insert_middle(int pos);
void searchNode(int StudentID);

void createNode(int n) {
    head = (node*)malloc(sizeof(node));
    printf("Enter Student 1 StudentID: ");
    scanf("%d", &head->StudentID);
    printf("Marks: ");
    scanf("%f", &head->Marks);
    printf("Section: ");
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
//Insert Value at First
void  new_nodeFirst()
{
 node *temp, *newnode;
 temp = head;
 newnode=(node*)malloc(sizeof(node));
    printf("New Student StudentID: ");
    scanf("%d", &newnode->StudentID);
    printf("Marks: ");
    scanf("%f", &newnode->Marks);
    printf("Section: ");
    getchar();
    scanf("%c", &newnode->Section);
    newnode->next=head;
    head=newnode;
}
// Insert Value at End
void insert_end()
{
    node *temp,*newnode;
    temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("Student 1 StudentID: ");
    scanf("%d", &newnode->StudentID);
    printf("Enter Student 1 Marks: ");
    scanf("%f", &newnode->Marks);
    printf("Enter Student 1 Section: ");
    getchar();
    scanf("%c", &newnode->Section);

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
     newnode->next=NULL;
}
// Add middle position
void insert_middle(int pos){
  node *newnode, *prev ,*current ,*temp;
    newnode=(node*)malloc(sizeof(node));
    printf("Student 1 StudentID: ");
    scanf("%d", &newnode->StudentID);
    printf("Enter Student 1 Marks: ");
    scanf("%f", &newnode->Marks);
    printf("Enter Student 1 Section: ");
    getchar();
    scanf("%c", &newnode->Section);
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
// Searching
void searchNode(int ID){
    node *temp;
    temp = head;
    while(temp != NULL)
        {
        if(temp->StudentID == ID)
        {
            printf("Search Item Found !!\n");
            break;
        }
        else{
            temp = temp->next;
        }
    }
    if(temp == NULL){
        printf("Search Item Not Found !!\n");
    }
}

void nodeDisplay() {
    node *value;
    int i = 1;
    value = head;
    printf("\n\nNode Print Successfully Done !!! \n");
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
    printf("Enter number of students : ");
    scanf("%d", &n);
    createNode(n);
    printf("\nLinkedList created successfully!\n");
    nodeDisplay();
    //Node First
    new_nodeFirst();
    nodeDisplay();
    //Node at Last
    insert_end();
    nodeDisplay();
    //Add random position
    printf("Enter any random number where you want :");
    int pos;
    scanf("%d",&pos);
    insert_middle(pos);
    // Search Which node  number
    printf("Enter  which Student_ID  you want to search :");
    int ID;
    scanf("%d",&ID);
    searchNode(ID);

    return 0;
}
