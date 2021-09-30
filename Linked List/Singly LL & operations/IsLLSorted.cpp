#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;

    public:
    Node* first;
    void CreateLL(int *A, int n);
    int IsSorted(Node* p);

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

int Node :: IsSorted(Node *p){
    int x = first->data;
    while (p)
    {
        if (p->data < x)
        {
            return false;
        }else{
            x = p->data;
            p = p->next;
        }
    }
    return true;
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
    
    if (N.IsSorted(N.first))
    {
        cout<<"The LL is Sorted!";
    }else{
        cout<<"The LL is not Sorted!";
    }

    return 0;
}
