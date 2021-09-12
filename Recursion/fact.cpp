#include<iostream>
using namespace std;

//Recursive code
int Rfact(int n){
    if(n==0){
        return 1;
    }
    return Rfact(n-1)*n;
}

//Iterative code
int Ifact(int n){
    int f=1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;

}


int main()
{
    int r = Rfact(4);
    int x = Ifact(5);
    cout<<r<<endl;
    cout<<x<<endl;
    return 0;
}
