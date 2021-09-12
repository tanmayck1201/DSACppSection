#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j;
    string s;
    cout<<"Enter a string: "<<endl;
    cin>>s;

    for(j=0; s[j]!='\0'; j++);
    
    j -= 1;
    for (i = 0; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    
    //reverse(s.begin(), s.end());
    cout<<s;
    return 0;
}