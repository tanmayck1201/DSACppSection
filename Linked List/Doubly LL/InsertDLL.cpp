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
    void Insertion(int pos, int x);
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

// Full case covering Insertio pgm(Inserts after a posn.): Min- O(1) & Max- O(n)
void DoublyLL::Insertion(int pos, int x)
{
    Node *t, *p = NULL;
    t = new Node;
    t->data = x;

    // pos less than 0- Invalid!
    if (pos < 0)
    {
        cout << "The Node can't be inserted!!";
    }

    // If it's 1st node going to be inserted!
    else if (first == NULL)
    {
        t->next = NULL;
        t->prev = NULL;
        first = last = t;
        cout << "The Node has been successfully Inserted!!" << endl;
    }

    // Insertion before 1st Node!
    else if (pos == 0)
    {
        t->prev = 0;
        t->next = first;
        first->prev = t;
        first = t;
        cout << "The Node has been successfully Inserted!!" << endl;
    }

    // Insertion after any given position!
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            t->prev = p;
            p->next = t;
            p->next->prev = t;

            // if insertion is at last Node, update last pointer!
            if (p == last)
            {
                t->prev = p;
                last = t;
            }
            cout << "The Node has been successfully Inserted!!" << endl;
        }

        // Invalid position - can't access!
        else
        {
            cout << "The Node can not be Inserted!!" << endl;
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

    cout << "Enter the data u want the new node with: ";
    cin >> x;
    cout << "At which position u want to insert Node with data " << x << " ?";
    cin >> pos;

    DoublyLL DL(A, n);
    DL.Insertion(pos, x);
    DL.DisplayLL();

    return 0;
}