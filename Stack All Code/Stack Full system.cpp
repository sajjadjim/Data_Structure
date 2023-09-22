#include<iostream>
using namespace std;
#define CAPACITY 3
int stack[CAPACITY];
int top = -1;

void push(int x)
{

 if( top == CAPACITY -1)
 {
  cout <<"Stack OVERflow....."<<endl;
 }
  else
  {
        //printf("Enter a value to push: ");
       // cout <<"Push new value in stacl :";
        //scanf("%d", &x); 
        cin >> stack[x];
        top = top + 1;
        stack[top] = x;
  }

}

int pop()
{

}

int display()
{
   if(top == -1)
   {
    cout <<"Stack Empty"<<endl;
   }
   else
   {
    cout <<"Display Stack ALL elements : ";
    for(int i= top ; i >= 0 ; i--)
    {
     cout << "|" << stack[i] << "|" <<endl;
    }
   }
}


int main()
{
   push(11);

   display();
}