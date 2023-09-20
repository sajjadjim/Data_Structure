#include<stdio.h>
#define CAPACITY 3
int stack[CAPACITY];
int top = -1;

void push(int x)  // Added the stack Value
{
    if( top < CAPACITY -1 )
    {
    top = top + 1;
    stack[top] = x;
    printf("Successfully added in stack : %d\n",x);
    }
    else
    {
        printf("Capacity overflow...........\n");
    }
}

int pop()  // Remove the stack value
{
 if(top >= 0)
 {
    int value = stack[top];
    top = top -1;
    return value;
 }
 printf("Stack is empty....................\n");
}

int peek() //Only see stack function Value
{
 if( top >= 0)
 {
    return stack[top];
 }
 printf("Stack is Empty .............\n");
 return -1;

}

int main()
{
   printf("My stack c............\n");
   peek();
   push(10);
   push(20);
   push(30);
   printf("\nRemove the stack value : %d\n",pop());
   push(40);
   printf("\nTop of stack value : %d \n",peek());
   return 0;
}
