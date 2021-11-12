#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLL
{
private:
    Node *first, *last;

public:
    DoublyLL()
    {
        first = NULL;
        last = NULL;
    }
    DoublyLL(int *A, int n);
    void ReverseLL();
    void DisplayLL();
    ~DoublyLL();
};

DoublyLL ::DoublyLL(int *A, int n)
{
    Node *t;
    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void DoublyLL::ReverseLL(){
    Node *p = 0;
    p = last = first;
    while (p)
    {
        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p->next == NULL)
        {
            p->next = p->prev;
            p->prev = nullptr;
            first = p;
            break;
        }
    }
}

void DoublyLL ::DisplayLL()
{
    Node *ptr = first;
    cout << "The elements are: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

DoublyLL ::~DoublyLL()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

int main()
{
    int *A, n;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    DoublyLL DL(A, n);
    DL.ReverseLL();
    DL.DisplayLL();

    return 0;
}