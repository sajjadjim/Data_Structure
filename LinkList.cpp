#include <iostream>
using namespace std;
struct student {
    int data;
    struct student *next; // Use student* instead of struct node*
}a,b,c,d;

int main() {
   // student a, b, c, d;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    d.data = 40;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL; // Use null pointer instead of NULL

    cout << "A Data = " << a.data << endl;
    cout << "B Data = " << b.data << endl;
    cout << "C Data = " << c.data << endl;
    cout << "D Data = " << d.data << endl << endl;

    cout << "Location of A address = " << a.next << endl;
    cout << "Location of B address = " << b.next << endl;
    cout << "Location of C address = " << c.next << endl;
    cout << "Location of D address = " << d.next << endl;

    return 0;
}







