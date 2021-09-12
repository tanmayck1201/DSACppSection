#include<iostream>
using namespace std;

int mfibo(int n, int F[]){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2]=mfibo(n-2,F);
        }
        if(F[n-1]==-1){
            F[n-1]=mfibo(n-1,F);
        }
        return F[n-2] + F[n-1];
    }
}

int main()
{
    int n;
    int F[10];
    for (int i = 0; i < 10; i++)
    {
        F[i]=-1;
    }
    cin>>n;
    cout<<"The term is "<<mfibo(n,F);

    return 0;
}