#include<iostream>
using namespace std;

int fun1(int n)
{
    // same procedure for static & then, global variable also.
    static int x=0;
    if(n>0){
        x++;
        cout<<fun1(n-1)+x<<endl;
    }
    return 0;
}

int main()
{
    int n=5,r;
    r = fun1(n);

    r = fun1(n);

    return 0;
}