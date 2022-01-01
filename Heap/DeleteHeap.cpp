// Delete from Heap & Heap Sort Pgm!
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

// Delete elements from heap
int DeleteHeap(int A[], int n)
{
    int x, i, j;
    // Always remove 1st/root element
    x = A[0];
    // Replace it with last element of array
    A[0] = A[n - 1];
    i = 0;
    j = (2 * i) + 1;
    // Run loop till replaced element(last oneth) has childs
    while (j <= n - 2)
    {
        // Check if left or right child, which is greater & use that element furthure!
        if (j < n - 2 && A[j + 1] > A[j])
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
    // Move deleted root element to last index of HEAP. (For heap sort)
    A[n - 1] = x;
    return x;
}

// Heap Sort
void HeapSort(int A[], int n)
{
    // Deleting all elements of heap 1 by 1 to get sorted array!
    for (int i = n; i > 0; i--)
    {
        DeleteHeap(A, i);
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

    cout << "Inplace Insert" << endl;
    createHeap(A, n);
    Print(A, n, 'A');
    cout << "The deleted element is: " << DeleteHeap(A, n) << endl;
    Print(A, n - 1, 'A');
    HeapSort(A, n - 1);
    cout << "After Heap Sort: " << endl;
    Print(A, n, 'A');

    return 0;
}
