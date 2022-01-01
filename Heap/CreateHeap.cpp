// Max Heap Creation Pgm!
#include <iostream>
using namespace std;

void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    // For min heap second condn will be reversed of while loop!
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertInplace(A, i);
    }
}

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

    cout << "Inplace Insert" << endl;
    createHeap(A, n);
    Print(A, n, 'A');

    return 0;
}