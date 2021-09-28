#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *first, *second, *q = NULL;
    void CreateLL(int *A, int n);
    void CreateLL2(int *A, int n);
    void Concatenate(Node *p);
    void DisplayLL(Node *ptr);
    int CountLL(Node *p);
};

void Node::CreateLL(int *A, int n)
{
    Node *t, *last1;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last1 = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last1->next = t;
        last1 = t;
    }
}

void Node::CreateLL2(int *A, int n)
{
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Node :: Concatenate(Node *p){
    while (p->next)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
    delete second;
}

void Node::DisplayLL(Node *ptr)
{
    cout << "The elements are: "<<endl;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next ;
    }
}

int main()
{
    int *A, n, c;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    Node N;
    N.CreateLL(A, n);
    N.CreateLL2(A, n);
    N.DisplayLL(N.first);
    N.Concatenate(N.first);
    N.DisplayLL(N.first);

    return 0;
}
