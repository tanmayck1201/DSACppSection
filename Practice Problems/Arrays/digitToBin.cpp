#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int main()
{
    int n, bin=10,i2;
    cin>>n;
    string s1;
    string s2;
    
    while(n>0)
    {
        int ld = n % 2;
        s1 = to_string(ld);
        s2 = s2 + s1;
        n = n/2;
    }
    reverse(s2.begin(), s2.end());
    cout<<s2;
    return 0;
}