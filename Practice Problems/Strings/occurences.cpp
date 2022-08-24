#include <bits/stdc++.h>
using namespace std;

int Occurences(int n1, int n2, string s1, string s2)
{
    int occ = 0;
    int j = 0;
    for (int i = 0; i < n1; i++)
    {
        if(s1[i] == s2[j])
        {
            j++;
        }else{
            j = 0;
        }
        if(j == n2)
        {
            j = 0;
            occ += 1;
        }
    }
    return occ;
}

int main()
{
    string s1, s2;
    s1 = "harihariharbol";
    s2 = "hari";
    int n1 = s1.size();
    int n2 = s2.size();
    cout<<Occurences(n1,n2,s1,s2);
}