#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLL
{
private:
    Node *head, *tail;

public:
    CircularLL()
    {
        head = NULL;
        tail = NULL;
    };
    CircularLL(int *A, int n);
    ~CircularLL();

    void Delete(int pos, int *A);
    void Display();
};

CircularLL ::CircularLL(int *A, int n)
{
    Node *t;
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

// Only thing is remn. that if pos is given more than LL count then what happens is not implemented, U can do it!!
void CircularLL ::Delete(int pos, int *A)
{
    Node *p, *q = NULL;
    int x = -1;

    // Invalid pointing!
    if (A == 0 || pos < 1)
    {
        cout << "The Node can't be deleted!!" << endl;
    }

    // If it's only 1 node present!
    else if (head->next == head)
    {
        x = head->data;
        delete head;
        head = tail = NULL;
    }

    // For 1st Node!
    else if (pos == 1)
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        p->next = head->next;
        delete head;
        head = p->next;
        delete p;
    }
    // For any given position!
    else
    {
        q = head;
        for (int i = 0; i < pos - 2; i++)
        {
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        x = p->data;

        // Updating tail pointer!
        if (p == tail)
        {
            tail = q;
        }
        delete p;
    }
    cout << "The deleted value is: " << x << endl;
}

void CircularLL ::Display()
{
    cout << "The Head Node is: " << head->data << endl;
    cout << "The Tail Node is: " << tail->data << endl;

    Node *p = head;
    cout << "The elements are: " << endl;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

CircularLL ::~CircularLL()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
}

int main()
{
    int *A, n, pos;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Enter the position from which u wanna delete node: ";
    cin >> pos;

    CircularLL CL(A, n);
    CL.Delete(pos, A);
    CL.Display();

    return 0;
}