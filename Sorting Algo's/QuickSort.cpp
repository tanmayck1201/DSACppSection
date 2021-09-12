#include <iostream>
using namespace std;

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        // Move i till we get greater element than pivot.
        do
        {
            i++;
        } while (A[i] <= pivot && i <= h);
        
        // Move j till we get lesser element than pivot.
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

void Display(int vec[], int n)
{
    cout << "The sorted elements are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    int n, *A;
    A = new int[20];
    cout << "Enter the no. of elements u want to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, n);
    Display(A, n);

    return 0;
}