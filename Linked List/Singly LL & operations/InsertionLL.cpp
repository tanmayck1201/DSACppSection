#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void CreateLL(int *A, int n);
    void InsertLL(int pos, int x);
    void InsertLL2(int pos, int x);
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

/* Given Code Inserts node at given posn, & also after last posn.
 To insert a node after a given posn u need to traverse LL, (pos-1) times with some minor changes! */
void Node::InsertLL(int pos, int x)
{
    Node *t, *p = NULL;
    t = new Node;
    t->data = x;
    if (pos < 1)
    {
        cout << "The Node can't be inserted!!";
    }

    if (pos == 1)
    {
        t->next = first;
        first = t;
        cout << "The Node has been successfully Inserted!!" << endl;
    }
    else if (pos > 1)
    {
        p = first;
        for (int i = 0; i < pos - 2 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
            cout << "The Node has been successfully Inserted!!" << endl;
        }
        else
        {
            cout << "The Node can not be Inserted!!" << endl;
        }
    }
}

// Full case covering Insertio pgm(Inserts after a posn.)
void Node::InsertLL2(int pos, int x)
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
        first = last = t;
        cout << "The Node has been successfully Inserted!!" << endl;
    }

    // Insertion before 1st Node!
    else if (pos == 0)
    {
        t->next = first;
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
            p->next = t;

            // if insertion is at last Node, update last pointer!
            if (p == last)
            {
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
    int *A, n, pos, x;
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
    cout << "At which position u want to insert Node with data " << x << " ?";
    cin >> pos;

    //N.InsertLL(pos, x);
    N.InsertLL2(pos, x);
    N.DisplayLL(first);

    return 0;
}