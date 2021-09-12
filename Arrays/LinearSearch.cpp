#include<iostream>
using namespace std;

struct Array
{
    float *A;
    int size;
    int l;
};

void Display(struct Array arr)
{
    cout<<"The array elements are: \n";
    for (int i = 0; i < arr.l; i++)
    {
        cout<<arr.A[i]<<endl;
    }
}

// call by referrence is used.
void swap(int &x, int &y){
    int t = x;
    x = y;
    y = t;
}

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->l; i++)
    {
        //With LS improvement logic by transposition method.
        if (arr->A[i]==key)
        {
            swap(arr->A[i], arr->A[i-1]);
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int n,key;
    struct Array arr;
    cout<<"Enter size of an array: ";
    cin>>arr.size;
    arr.A = new float[arr.size];
    arr.l = 0;

    cout<<"Enter no. of elements to enter: ";
    cin>>n;

    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
            cin>>arr.A[i];
    }
    arr.l = n;

    cout<<"Enter element to be searched: ";
    cin>>key; 

    Display(arr);
    cout<<"The element is found at position "<<LinearSearch(&arr,key)<<endl;
    Display(arr);

    return 0;
}

