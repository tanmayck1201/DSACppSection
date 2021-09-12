#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;

    public:
    Node* first;
    void CreateLL(int *A, int n);
    int CountLL(Node* p);

};

void Node::CreateLL(int *A, int n){
    Node *t, *last;
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

int Node :: CountLL(Node *p){
    if(p==0)
        return 0;
    else
        return 1 + CountLL(p->next);    
}

int main()
{
    int *A, n, c;
    cout<<"Enter the size: ";
    cin>>n;
    A = new int[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    
    Node N;
    N.CreateLL(A, n);
    c = N.CountLL(N.first);

    cout<<"The Nodes in the LL are: "<<c;

    return 0;
}