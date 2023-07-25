#include<iostream>
using namespace std;
int main()
{   // Array
    int x[5] ={10,20,30,40,50};
    int *p;

    for(int i=0 ; i< 5; i++)
    {
      //  cout << &x[i] << endl;
        cout <<"Address ="<< i<<" "<<&x[i] << endl;
    }
    p = x;
    cout <<"**** Second Address ****"<<endl;
   // By default First Address print
   for (int i=0 ; i<5 ;i++)
   {
       cout << (p+i) << endl;
   }
return 0;
}
