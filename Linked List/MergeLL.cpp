#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node *first, *second, *T3 = NULL;
    void CreateLL(int *A, int n);
    void CreateLL2(int *A, int n);
    void MergeLL(Node *first, Node *second);
    void DisplayLL(Node *ptr);
};

void Node::CreateLL(int *A, int n)
{
    Node *t, *last1;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last1 = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last1->next = t;
        last1 = t;
    }
}

void Node::CreateLL2(int *A, int n)
{
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Node::MergeLL(Node *first, Node *second)
{
    Node *L;

    if (first->data > second->data)
    {
        T3 = L = second;
        second = second->next;
        T3->next = NULL;
    }
    else
    {
        T3 = L = first;
        first = first->next;
        T3->next = NULL;
    }

    while (first && second)
    {
        if (first->data > second->data)
        {
            L->next = second;
            L = second;
            second = second->next;
            L->next = NULL;
        }
        else
        {
            L->next = first;
            L = first;
            first = first->next;
            L->next = NULL;
        }
    }

    if (second)
    {
        L->next = second;
    }
    if (first)
    {
        L->next = first;
    }
}

void Node::DisplayLL(Node *ptr)
{
    cout << "The elements are: " << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    // 1st array for 1st LL
    int *A, *A2, n, n2, c;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // 2nd array for 2nd LL
    cout << "Enter the size: ";
    cin >> n2;
    A2 = new int[n2];
    cout << "Enter the elements: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> A2[i];
    }

    Node N;
    N.CreateLL(A, n);
    N.CreateLL2(A2, n2);
    N.MergeLL(N.first, N.second);
    N.DisplayLL(N.T3);

    return 0;
}
