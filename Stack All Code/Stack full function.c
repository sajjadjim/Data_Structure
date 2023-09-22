#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top >= MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
        return false;
    } 

    else 
    {
        top = top + 1;
        stack[top]=value;
        return true;
    }
}

// Function to pop an element from the stack
int pop() 
{
    if (top == -1)
     {
        printf("Stack Underflow\n");
        return false;
    }

    else 
    {
        top--;
        return true;
    }
}

// Function to display the elements of the stack
void display() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
    }

     else {
        printf("Stack elements: \n");
        for (int i = 0; i <= top; i++) 
        {
            printf("|%d| \n", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    display(); // Display: 10 20 30
    
    pop();
    
    display(); // Display: 10 20
    
    push(40);
    
    display(); // Display: 10 20 40
    
    return 0;
}
