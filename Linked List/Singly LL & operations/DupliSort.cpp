#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *first;
    void CreateLL(int *A, int n);
    void IsDuplicate(Node *p);
    void DisplayLL(Node *ptr);
};

void Node::CreateLL(int *A, int n)
{
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

void Node ::IsDuplicate(Node *p)
{
    Node *q;
    q = p->next;
    while (q)
    {
        p = q;
        q = q->next;
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
            cout << "The duplicate element is: " << p->data<<endl;
        }
    }
}

void Node::DisplayLL(Node *ptr)
{
    cout << "The elements are: ";
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
    N.IsDuplicate(N.first);
    N.DisplayLL(N.first);

    return 0;
}
