#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void CreateLL(int *A, int n);
    int CountLL();
    void InsertLL2(int pos, int x);
    void DisplayLL(Node *ptr);
};
Node *head, *tail = NULL;

void Node::CreateLL(int *A, int n)
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

int Node ::CountLL()
{
    Node *p = head;
    int len = 0;
    if (p == NULL)
    {
        return len;
    }
    else
    {
        do
        {
            len++;
            p = p->next;
        } while (p->next != head);

        return len;
    }
}

// Full case covering Insertion CLL pgm(Inserts after a posn.)
void Node::InsertLL2(int pos, int x)
{
    Node *t, *p = NULL;
    t = new Node;
    t->data = x;
    p = head;

    // pos less than 0- Invalid!
    if (pos < 0 || pos > CountLL())
    {
        cout << "The Node can't be inserted!!";
    }

    // Insertion before 1st Node!
    else if (pos == 0)
    {
        // If it's 1st node going to be inserted!
        if (head == NULL)
        {
            head = t;
            head->next = head;
            cout << "The Node has been successfully Inserted!!" << endl;
        }
        else
        {
            t->next = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            head = t;

            cout << "The Node has been successfully Inserted!!" << endl;
        }
    }

    // Insertion after any given position!
    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;

        // if insertion is at tail Node, update tail pointer!
        if (t->next == head)
        {
            tail = t;
        }
        cout << "The Node has been successfully Inserted!!" << endl;
    }

    // Invalid position - can't access!
    else
    {
        cout << "The Node can not be Inserted!!!" << endl;
    }
}

void Node::DisplayLL(Node *ptr)
{
    Node *p = head;
    cout << "The elements are: " << endl;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
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
    N.DisplayLL(head);

    return 0;
}