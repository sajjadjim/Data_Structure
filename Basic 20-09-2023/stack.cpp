#include<iostream>
#define CAPACITY 3
int stack[CAPACITY];
using namespace std;
int top = -1;
void push(int x)
{
    if( top < CAPACITY-1)
    {
        top = top +1;
        stack[top] =x;
        cout <<"Stack value added : " <<stack[top]<<endl;
    }
    else{
        cout <<"Stack Size overflow......\n";
    }
}

int pop()
{
    if( top >= 0 )
    {
        int value = stack[top];
        top = top -1;
        return value;
    }
    cout <<"Stack has no value to remove .............."<<endl;
    return -1;

}

int peek()
{
 if( top >= 0 )
 {
     return stack[top];
 }
  cout << "Stack has no Data......" << endl;
  return -1;
}

int main()
{
    cout <<"My Stack C++................!!!!"<<endl<<endl;
    push(11);
    push(22);
    push(33);
    cout <<endl<<"Peek Value(last Value) is : " <<peek()<< endl<<endl;
    cout <<"Remove value from stack : "<<pop()<<endl<<endl;
    push(44);
    return 0;
}
