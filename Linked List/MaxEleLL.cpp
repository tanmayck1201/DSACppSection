#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node *first = NULL;

void CreateLL(int *A, int n){
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


//Recursive Func.
int MaxElement(struct Node *ptr){
    static int y = ptr->data;
    int x = 0;
    if(ptr==0){
        return y;
    }

    x = MaxElement(ptr->next);

    // Ternary operator used.
    return x > ptr->data ? x : ptr->data;
}


int main()
{
    int *A, n;
    cout<<"Enter the size: ";
    cin>>n;
    A = new int[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }

    CreateLL(A,n);
    cout<<"The Max element is: "<<MaxElement(first);

    return 0;
}