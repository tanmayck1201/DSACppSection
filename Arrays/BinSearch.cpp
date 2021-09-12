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

/*int BinSearch(struct Array arr, int key)
{
    int l=0;
    int h=arr.l-1;

    while (l<=h)
    {
        int mid = (l+h)/2;
        if(arr.A[mid]==key){
            return mid;
        }
        else if (key<arr.A[mid])
        { 
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    return -1;
}*/


//Recursion Algo.
int RBinSearch(float A[], int l, int h, int key)
{
    while (l<=h)
    {
        int mid = (l+h)/2;
        if(A[mid]==key){
            return mid;
        }
        else if (key<A[mid])
        {
            return RBinSearch(A, l, mid-1, key);
        }
        else{
            return RBinSearch(A, mid+1, h, key);
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

    cout<<"Enter the elements: \n";
    for (int i = 0; i < n; i++)
    {
            cin>>arr.A[i];
    }
    arr.l = n;

    Display(arr);
    
    cout<<"Enter element to be searched: ";
    cin>>key; 
    //cout<<"The element is found at index "<<BinSearch(arr,key)<<endl;
    cout<<"The element is found at index "<<RBinSearch(arr.A,0,arr.l,key)<<endl;

    return 0;
}

