// Heapify - Fastest way to create heap!
#include <iostream>
using namespace std;

template <class T>
void Print(T &vec, int n, char c)
{
    cout << c << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Create heap using Heapify!
void Heapify(int A[], int n)
{
    int i, j;
    // Start loop from last element of array till root!
    // starting with (n/2)-1 as it it's index of last leaf element's parent
    // leaf nodes not require to go thr' loop as they've no child(s)!!
    for (i = (n / 2) - 1; i >= 0; i--)
    {
        j = (2 * i) + 1;
        // Run loop till replaced element(last oneth) has childs
        while (j <= n - 1)
        {
            // Check if left or right child, which is greater & use that element furthure!
            if (j < n - 1 && A[j + 1] > A[j])
            {
                j = j + 1;
            }
            // compare that element with replaced element
            if (A[i] < A[j])
            {
                // if greater, swap those & move j to replced elements next left child!
                swap(A[i], A[j]);
                i = j;
                j = (2 * j) + 1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int n, *A;
    cout << "Create Max Heap" << endl;
    cout << "Enter the no. of elements u want to enter: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Print(A, n, 'A');

    cout << "Inplace Insert using Heapify" << endl;
    Heapify(A, n);
    Print(A, n, 'A');

    return 0;
}
