// This is an ideal cpp pgm for all types of operations on LL, as well as for destructor working!
#include <iostream>
using namespace std;

// For Nodes
class Node
{
public:
    int data;
    Node *next;
};

// For LL
class LinkedList
{
private:
    Node *first, *last;

public:
    // Default constructor!
    LinkedList()
    {
        first = NULL;
        last = NULL;
    }
    LinkedList(int *A, int n);
    ~LinkedList();

    int CountLL();
    void DisplayLL();
};

// Creates LL using parameterized constructor!
LinkedList::LinkedList(int *A, int n)
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

// Deletes all nodes after execution!
LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
    cout << "Hii";
}

// Count the no. of nodes in LL.
int LinkedList ::CountLL()
{
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Displays LL.
void LinkedList::DisplayLL()
{
    Node *ptr = first;
    cout << "The elements are: " << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
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

    LinkedList L(A, n);
    c = L.CountLL();
    L.DisplayLL();

    cout << "The Nodes in the LL are: " << c << endl;

    return 0;
}