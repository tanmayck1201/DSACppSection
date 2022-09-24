#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    private:
    Node *first, *last;

    public:
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
    }
    // ~LinkedList();

    void CreateLL(int*A, int n);
    void DisplayLL();
};

void LinkedList::CreateLL(int* A, int n)
{
    Node* t = 0;
    first = new Node;
    last = first;
    first->data = A[0];
    first->next = 0;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void LinkedList::DisplayLL()
{
    Node* p = first;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int *A = new int[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }

    // Node N;
    LinkedList L;
    L.CreateLL(A, n);
    L.DisplayLL();

    return 0;
}
