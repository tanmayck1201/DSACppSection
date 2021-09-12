#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first, *last = NULL;

void CreateLL(int *A, int n){
    struct Node *t;
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

void Append(int x){
    struct Node *t = NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void DisplayLL(Node *ptr){
    cout<<"The elements are: ";
    while(ptr!=NULL){
        cout<<ptr->data<<" " ;
        ptr = ptr->next;
    }
}

int main()
{
    int *A, n, x;
    cout<<"Enter the size: ";
    cin>>n;
    A = new int[n];
    cout<<"Enter the string: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    CreateLL(A, n);
    cout<<"Enter the value to be inserted at last node: "<<endl;
    cin>>x;
    Append(x);
    DisplayLL(first);

    return 0;
}