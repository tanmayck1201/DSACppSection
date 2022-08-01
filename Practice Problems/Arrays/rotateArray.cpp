
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        int p[d] = {0};
        int i, j;

        if (d == 0 || d > n)
        {
            return;
        }

        for (i = 0; i < d; i++)
        {
            p[i] = arr[i];
        }

        for (j = 0, i = d; i < n; i++, j++)
        {
            arr[j] = arr[i];
        }

        for (j = 0, i = n - d; i < n; i++, j++)
        {
            arr[i] = p[j];
        }
    }
};


int main()
{
    int t = 1;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        // input n and d
        cin >> n >> d;

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}