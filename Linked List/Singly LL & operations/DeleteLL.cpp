#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void CreateLL(int *A, int n);
    void DeleteNode(int pos, int *A);
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

// Complete DeleteNode Pgm: Min- O(1) & Max- O(n)
void Node::DeleteNode(int pos, int *A)
{
    Node *p, *q = NULL;
    int x = -1;

    // Invalid pointing!
    if (A==0 || pos < 1 )
    {
        cout<<"The Node can't be deleted!!"<<endl;
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
        delete p;
    }
    // For any given position!
    else
    {
        p = first;
        q = NULL;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            
            // Updating last pointer!
            if (p == last)
            {
                last = q;
            }
            delete p;
        }
    }
    cout << "The deleted value is: " << x << endl;
}

void Node::DisplayLL(Node *ptr)
{
    cout<<"The first Node is: "<<first->data<<endl;
    cout<<"The last Node is: "<<last->data<<endl;

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
    int *A, n, pos;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    N.CreateLL(A, n);

    cout << "Enter the position from which u wanna delete node: ";
    cin >> pos;
    N.DeleteNode(pos, A);
    N.DisplayLL(first);

    return 0;
}