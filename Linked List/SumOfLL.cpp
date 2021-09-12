#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;

    public:
    Node* first;
    void CreateLL(int *A, int n);
    int SumLL(Node* ptr);

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

int Node::SumLL(Node* ptr){
    int x=0;
    while (ptr != NULL)
    {
        x = x + ptr->data;
        ptr = ptr->next;
    }
    return x;

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
    cout<<"The sum of all elements in LL is: "<< N.SumLL(N.first);

    return 0;
}