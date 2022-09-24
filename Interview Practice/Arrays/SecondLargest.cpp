#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[6] = {22, 78, 44, 33, 7, 76};
    // pass in addresses of start & end of array.
    sort(A, A+6, greater<int>());
    cout << A[1];

    return 0;
}
