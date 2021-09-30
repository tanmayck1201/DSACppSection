#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *first, *q = NULL;
    void CreateLL(int *A, int n);
    void ReverseLL(Node *p);
    void ReverseLL2(Node *p);
    void ReverseLL3(Node *q, Node *p);
    void DisplayLL(Node *ptr);
    int CountLL(Node *p);
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

int Node :: CountLL(Node *p){
    if(p==0)
        return 0;
    else
        return 1 + CountLL(p->next);    
}

// Using Interchanging of data.
void Node ::ReverseLL(Node *p)
{
    int i, x;
    // Make an auxillary array of size of LL nodes.
    x = CountLL(first);
    int *A = new int[x];
    // copy the LL data to array made.
    for (i = 0; i < x; i++)
    {
        A[i] = p->data;
        p = p->next;
    }
    i = i-1;
    p = first;
    // copy array ele. to LL data now, so it'll be in reverse manner. 
    for (; i >= 0; i--)
    {
        p->data = A[i];
        p = p->next;
    }
}

// Using sliding pointers method.(Prefferable)
void Node ::ReverseLL2(Node *p)
{
    Node *q = NULL, *t = NULL;
    // Traverse LL & concurrently make links of LL in reverse manner.
    while (p != NULL)
    {
        t = q;    
        q = p;
        p = p->next;
        q->next = t;
    }
    // At last node now, make it as first!
    first = q;
}

// Using Sliding pointers method in recursive manner.
void Node ::ReverseLL3(Node *q, Node *p)
{
    // Tail recursion
    if (p)
    {
        ReverseLL3(p, p->next);
        // returning phase part
        p->next = q;
    }else{
        first = q;
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
    //N.ReverseLL2(N.first);
    N.ReverseLL3(N.q, N.first);
    N.DisplayLL(N.first);

    return 0;
}
