#include<iostream>
using namespace std;

int main()
{
    char A[100];
    cout<<"Enter string: "<<endl;
    cin.get(A, 100);
    for (int i = 0; A[i]!='\0'; i++)
    {
        // for conversion to lower case
        if(A[i]>=65 && A[i]<=90)
            A[i]=A[i]+32;  

        // for conversion to upper case    
        else if(A[i]>='a' && A[i]<=122)
            A[i] -= 32;    
    }  
    cout<<A;
    
    return 0;
}
