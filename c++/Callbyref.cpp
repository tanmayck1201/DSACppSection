#include<iostream>
using namespace std;

void swapref(int &a, int&b)
{
    int t = a;
    a=b;
    b=t;
}


int main()
{
    int x=2, y=8;
    cout<<"The value of x & y are: "<<x<<" and "<<y<<endl;
    swapref(x,y);
    cout<<"The value of x & y are: "<<x<<" and "<<y<<endl;
    return 0;
}

