#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void CreateLL(int *A, int n);
    void LoopCheck(Node *p);
    void DisplayLL(Node *ptr);
    // Destructor
    ~Node();
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
    // making loop in LL.
    last->next = first->next->next;
}

// Using sliding pointers method!
void Node::LoopCheck(Node *p)
{
    int flag = 0;
    Node *q;
    q = p;
    while (q) 
    {
        p = p->next;
        q = q->next;
        // Don't blindly make 'q' to next node so,
        q=q!=NULL?q->next:NULL;
        if (p == q && first->next != NULL)
        {
            cout << "There's loop in given Linked List!!";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "The given LL contains no loop!";
    }
}

// Display will cause infinite loop!!
/*void Node::DisplayLL(Node *ptr)
{
    cout << "The elements are: ";
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}*/

// Destructor!
Node::~Node(){
    Node* p = first;
    while (first)
    {
        first->next;
        delete p;
        p = first;
    }
    cout<<"Hii";
}

int main()
{
    Node N;
    int *A, n;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    N.CreateLL(A, n);
    N.LoopCheck(first);
    //N.DisplayLL(first);

    return 0;
}