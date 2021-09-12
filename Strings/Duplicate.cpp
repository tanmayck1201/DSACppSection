#include<iostream>
using namespace std;

int main()
{
    string A;
    cout<<"Enter String: "<<endl;
    getline(cin, A);
    int H=0, x=0;

    for (int i = 0; i < A.length(); i++)
    {
        x=1;
        x=x<<A[i]-97;

        if ((x&H) > 0)
        {
            cout<<"The Duplicate element is: "<<A[i]<<endl;
        }else{
            H=x|H; 
        }
    }
    
    return 0;
}   
