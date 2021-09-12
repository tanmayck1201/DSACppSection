#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    
    void CreateLL(int *A, int n);
    Node *SearchLL(Node *p, int key);
    Node *TransposeLS(Node *p, int key);
    Node *ImprovedLS(Node *p, int key);
    void DisplayLL(struct Node *ptr);
};
Node *first;

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

// Normal LS.
Node *Node::SearchLL(Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// MoveToFront Method.
Node *Node::ImprovedLS(Node *p, int key)
{
    Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            if (p == first)
            {
                return p;
            }
            else
            {
                q->next = p->next;
                p->next = first;
                first = p;
                return p;
            }
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Transpose Method.
Node *Node::TransposeLS(Node *p, int key)
{
    Node *q, *t = NULL;
    while (p)
    {
        // If key element is found!
        if (key == p->data)
        {
            // If key found is at first node.
            if (p == first)
            {
                return p;
            }
            // For Key found at any other nodes.
            else
            {
                // spl. condition if key found is at 2nd node.
                if (p->data == first->next->data)
                {
                    first = p;
                }

                q->next = p->next;
                p->next = q;

                if (t != NULL)
                {
                    t->next = p;
                }

                return p;
            }
        }
        t = q;
        q = p;
        p = p->next;
    }
    return NULL;
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
    Node *temp;
    int *A, n, key;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> key;

    N.CreateLL(A, n);

    // Only 1 func.(Normal) is used here, can try others also!
    temp = N.SearchLL(first, key);
    if (temp)
    {
        cout << "The element is found " << temp->data << endl;
        /*cout<<"The element is found "<<temp<<endl;
        cout<<"The element is found "<<&temp->data<<endl;
        cout<<"The element is found "<<&temp->next<<endl;
        cout<<"The element is found "<<temp->next->next<<endl;*/
    }

    else
    {
        cout << "The key not found!!" << endl;
    }

    N.DisplayLL(first);

    return 0;
}
