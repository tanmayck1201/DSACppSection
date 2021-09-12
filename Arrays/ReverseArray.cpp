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
void swap(float *x, float *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void ReverseArray(struct Array *arr)
{
    float *B;
    int i,j;
    B = new float[arr->l];

    for ( i = arr->l-1, j=0; i>=0; i--,j++)
    {
        B[j]=arr->A[i];
    }
    for ( i = 0; i <= arr->l-1; i++)
    {
        arr->A[i]=B[i];
    }
}

void ReverseArray2(struct Array *arr)
{
    int i,j;

    for ( i = 0, j=arr->l-1; i<=j; i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
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

    //ReverseArray(&arr);
    ReverseArray2(&arr);
    Display(arr);

    return 0;
}


