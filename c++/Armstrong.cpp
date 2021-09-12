#include<iostream>
#include"math.h"
using namespace std;

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int sum=0;
    int myn=n;

    while (n>0)
    {
        int lastdigit = n % 10;
        sum += pow(lastdigit,3);
        n = n/10;
    }    

    if(myn==sum){
        cout<<"Armstrong!";
    }
    else{
        cout<<"Not Armstrong!";
    }
    
    return 0;
}