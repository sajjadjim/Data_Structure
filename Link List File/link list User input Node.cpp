#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;
}*head;
typedef struct node nodal;
void createNode(int n);
void displayNode();

void createNode(int n)
{
  head =(nodal*)malloc(sizeof(nodal));
  cout <<"Enter node 1 data :";
  cin >>head->data;
  head->next=NULL;

  nodal *newnode ,*temp;
  temp=head;

  for(int i=2; i<=n ; i++)
  {
    newnode =(nodal*)malloc(sizeof(nodal));
    cout <<"Enter node "<<i<<" data : ";
    cin >>newnode->data;
    newnode->next = NULL;
    temp->next = newnode;
    temp= temp->next;
  }
}
void displayNode()
{
    nodal *value=head;
    int i=1;
    while(value != NULL)
    {
        cout <<"Node "<<i<<" data :"<<value->data<<endl;
        value = value->next;
        i++;
    }
    cout <<endl<<endl;
}
void create_node_first()
{
nodal *newnodeFirst;
newnodeFirst = (nodal*)malloc(sizeof(nodal));
cout <<"Enter new data at First : ";
cin >> newnodeFirst->data;

newnodeFirst->next = head; // Newnode next add to the head pointer value
head = newnodeFirst;  // Here initialization the new node first to head
}

int main()
{
    int n;
    cout << "Enter number of nodes :";
    cin >>n;
    createNode(n);
    cout << endl <<"Node create Successfully !"<< endl;
    displayNode();
// ADD node First position 
    create_node_first();
    cout <<endl<<"New node added to the first !"<<endl;
    displayNode();
    return 0;
}