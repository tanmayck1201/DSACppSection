#include <iostream>
using namespace std;

class BubbleSort
{
private:
    int *A, n, x, flag;

public:
    BubbleSort(int n);
    void Bsort(); 
    void swap(int *x, int *y);
    void display();
    ~BubbleSort();
};

BubbleSort::BubbleSort(int n)
{
    A = new int[n];
    cout << "Enter the no. of elements u want to enter: ";
    cin >> x;
    cout << "Enter the elements in an array: " << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> A[i];
    }
}

void BubbleSort::Bsort()
{
    flag = 0;
    // for no. of passes
    for (int i = 0; i < x - 1; i++)
    {
        // for no. of comparisons
        for (int j = 0; j < x - 1 - i; j++)
        {
            //to decide swaps
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        // To make it adaptive.
        if(flag == 0){
            return;
        }
    }
}

void BubbleSort::display()
{
    if(flag == 1){
        cout << "The Sorted elements are: " << endl;
        for (int i = 0; i < x; i++)
        {
            cout << A[i] << " ";
        }
    }
    else{
        cout<<"The list is already sorted!!";
    }    
}

void BubbleSort::swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

BubbleSort::~BubbleSort()
{
    delete[] A;
}

int main()
{
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    BubbleSort B(n);
    B.Bsort();
    B.display();

    return 0;
}


