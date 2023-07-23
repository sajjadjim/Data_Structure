#include<iostream>
#include<stdlib.h>
using namespace std;

struct student{
 int id;
 float cgpa;
 struct student *next;
};  //*std1,*std2,*std3
typedef struct student node;  // Here decleaire the 'Node'

int main()
{
  node *std1 , *std2 ,*std3;

  std1 = (node*)malloc(sizeof(node));
  std2 = (node*)malloc(sizeof(node));
  std3 = (node*)malloc(sizeof(node));

  std1->id = 5364;
  std1->cgpa = 3.42;
  std1->next = std2;

  std2->id =5566;
  std2->cgpa = 3.55;
  std2->next = std3;

  std3->id =5090;
  std3->cgpa = 3.34;
  std3->next = NULL;


cout << "Student ID =" << std1->id << endl;
cout << "Student CGPA =" << std1->cgpa << endl << endl;

cout << "Student ID =" << std2->id << endl;
cout << "Student CGPA =" << std2->cgpa << endl << endl;

cout << "Student ID =" << std3->id << endl;
cout << "Student CGPA =" << std3->cgpa << endl << endl;

return 0;
}
