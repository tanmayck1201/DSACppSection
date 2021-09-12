#include<iostream>
using namespace std;

void duplicate(int H[], string str){
    // Traverse the string & incr. array index with no. of times element appeared.
    for (int i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 64] += 1;
    }
    
    // Check for duplicates.
    for (int i = 0; i < 58; i++)
    {
        // H[i]=1 means ele. present is single/unique!
        if(H[i] > 1){
            cout<<"The Duplicate element is "<<char(i+64)<<" with "<<H[i]<<" no. of times!"<<endl;
        }
    }
}


int main()
{
    string str;
    // Hash array to store total 52 chars(S/C) with additional gap.
    int H[58] = {0};
    cout<<"Enter the string: ";
    getline(cin, str);

    duplicate(H, str);

    return 0;
}