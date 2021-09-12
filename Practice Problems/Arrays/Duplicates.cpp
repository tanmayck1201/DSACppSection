#include <iostream>
using namespace std;

int SortedDuplicates(int *A, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == A[i + 1] && A[i - 1] != A[i])
        {
            int j = i + 1;
            while (A[j] == A[i])
                j++;
            cout << "The Duplicate element " << A[i] << " is appearing " << j - i << " times!" << endl;
            count++;
            i = j - 1;
        }
    }
    return count;
}

// Incomplete
int Duplicates(int *A, int n)
{
    int count = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j] && A[i] != -1)
            {
                count++;
                A[j] = -1;
            }
        }
        if (count > 1)
        {
            cout << "The Duplicate element " << A[i] << " is appearing " << count << " times!" << endl;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    int A[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int x = Duplicates(A, n);

    cout << "The no. of duplicate elements are: " << x;

    return 0;
}