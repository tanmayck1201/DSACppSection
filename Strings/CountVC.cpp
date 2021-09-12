#include<iostream>
using namespace std;

void Check(char *A)
{
    int vcount=0, ccount=0;
    for (int i = 0; A[i]!='\0' ; i++)
    {
        // To count vowels
        if (A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U')
        {
            vcount++;
        }
        
        // To count consonants
        else if ((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122))
        {
            ccount++;
        }
    }
    cout<<"The vowels in the string are: "<<vcount<<endl;
    cout<<"The consonants in the string are: "<<ccount<<endl;
}


int main()
{
    char *A[20];
    cout<<"Input String: ";
    cin.get(*A, 20);

    Check(*A);

    return 0;
}
