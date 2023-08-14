#include<iostream>
using namespace std;
int main()
{   int a;
    a=10;
    int *p;
    p = &a;
    cout << a  <<  endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;

    *p = 20;
    cout << a << endl;

    a = 20;
    cout << *p<< endl << endl;
    // Array
    int x[5] ={10,20,30,40,50};
    int *p;
    for(int i=0 ; i< 5; i++)
    {
        cout << &x[i] << endl;
    }
    cout <<endl<< &x << endl; // By default First Address print

    p = &x ;
    cout << p;
    return 0;
}
