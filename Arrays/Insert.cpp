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

void append(struct Array &arr, int x)
{
    if(arr.l<arr.size){
        arr.A[arr.l]=x;
        //arr.A[arr.l++];
    }
}

void insert(struct Array *arr, int index, float x)
{
    if(index>=0 && index<=arr->l){
        for (int i = arr->l; i > index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->l++;
    }
}

int main()
{
    int n;
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

    Display(arr);
    append(arr, 25);
    Display(arr);
    insert(&arr,3,23.58);
    Display(arr);

    return 0;
}

