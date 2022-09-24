// setup code - template name
#include<iostream>
using namespace std;

void ReverseArray(int *A, int size)
{
    int i, j= size-1;
    for (int i = 0; i < j; i++, j--)
    {
        swap(A[i], A[j]);
    }
    i=0;
    for (int i = 0; i < size; i++)
    {
        cout<<A[i]<<endl;
    }
}

int main()
{
    int *A, size;
    cout<<"Enter size of an array: ";
    cin>>size;

    A = new int[size];
    cout<<"Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin>>A[i];
    }
    ReverseArray(A, size);

    return 0;
}