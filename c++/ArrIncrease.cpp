#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int *p, *q;
    p=new int[5];
    p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;
    
    q=new int[10];
    memcpy(q,p,sizeof(p));

    for (int i = 0; i < 5; i++)
    {
        cout<<q[i]<<endl;
    }

    return 0;
}