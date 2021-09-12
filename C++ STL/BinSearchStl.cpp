#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A[] = {1,4,5,6,54,86,7,75,6};
    bool res = binary_search(A,A+9,25);
    if(res){
        cout<<"Present!";
    }else{
        cout<<"Not Present!";
    }

    return 0;
}

