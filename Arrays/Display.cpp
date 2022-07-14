#include <iostream>
using namespace std;

void Display(struct Array arr);

struct Array
{
    int *A;
    int size;
    int l;
};

int main()
{
    int n;
    struct Array arr;
    cout << "Enter size of an array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.l = 0;

    cout << "Enter no. of elements to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr.A[i];
    }
    arr.l = n;

    Display(arr);

    return 0;
}

void Display(struct Array arr)
{
    cout << "The array elements are: \n";
    for (int i = 0; i < arr.l; i++)
    {
        cout << arr.A[i] << endl;
    }
}
