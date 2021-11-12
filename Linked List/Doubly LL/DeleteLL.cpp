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
    void DeleteNode(int pos, int *A);
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

// Complete DeleteNode Pgm: Min- O(1) & Max- O(n)
void DoublyLL::DeleteNode(int pos, int *A)
{
    Node *p = NULL;
    int x = -1;

    // Invalid pointing!
    if (A == 0 || pos < 1)
    {
        cout << "The Node can't be deleted!!" << endl;
    }

    // If it's only 1 node present!
    else if (first->next == NULL)
    {
        x = first->data;
        first = last = NULL;
    }

    // For 1st Node!
    else if (pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        if (first)
            first->prev = 0;
        delete p;
    }

    // For any given position!
    else
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            x = p->data;
            if (p->next)
                p->next->prev = p->prev;
            p->prev->next = p->next;

            // Updating last pointer!
            if (p == last)
            {
                p->prev->next = 0;
                last = p->prev;
            }
            delete p;
        }
    }
    cout << "The deleted value is: " << x << endl;
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
    Node N;
    int *A, n, x, pos;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the pos from which you want to delete the node: ";
    cin >> pos;

    DoublyLL DL(A, n);
    DL.DeleteNode(pos, A);
    DL.DisplayLL();

    return 0;
}