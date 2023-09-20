#include<stdio.h>
int top=-1;
int stack[];

void push(int maxstack)
{
    int x;
    for(int i=1; i<=maxstack; i++)
    {
        if(top==maxstack-1)
        {
            printf("Overflow.");
        }
        else
        {
            printf("Enter data for stack:%d\n",i);
            scanf("%d",&x);
            top++;
            stack[top]=x;
        }
    }

}
void pop(int maxstack)
{
    for(int i=0; i<maxstack; i++)
    {
        if(top==-1)
            printf("Underflow");
        else
        {
            printf("%d ",stack[top]);
            top--;
        }
    }
}
void display()
{
    if(top==-1)
        printf("Stack is empty");
    else
    {
        for(int i=0; i<=top; i++)
            printf("%d->",stack[i]);
    }
}
int main()
{
    int maxstack;
    printf("Enter how many data in Stack: ");
    scanf("%d",&maxstack);
    push(maxstack);

    printf("\n Stack:");
    display();

    printf("\n\n After pop data from stack:");
    pop(maxstack);

    printf("\n\n After pop element from the stack: ");
    display();

}
