#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void CreateLL(int *A, int n);
    void InsertInSort(int x);
    void DisplayLL(Node *ptr);
};
Node *first, *last = NULL;

void Node::CreateLL(int *A, int n)
{
    Node *t;
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

void Node::InsertInSort(int x)
{
    Node *t, *p, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    p = first;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Node::DisplayLL(Node *ptr)
{
    cout << "The elements are: ";
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node N;
    int *A, n, x;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    N.CreateLL(A, n);

    cout << "Enter the data u want the new node with: ";
    cin >> x;
    N.InsertInSort(x);
    N.DisplayLL(first);

    return 0;
}