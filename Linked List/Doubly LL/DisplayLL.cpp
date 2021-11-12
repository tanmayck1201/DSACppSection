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
    };
    DoublyLL(int *A, int n);
    ~DoublyLL();

    void Display();
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

void DoublyLL ::Display()
{
    cout << "The first data is: " << first->data << endl;
    cout << "The first next data is: " << first->next->data << endl;
    cout << "The first next data again is: " << first->next->next->prev->data << endl;
    cout << "The second last data is: " << last->prev->data << endl;
    cout << "The last data is: " << last->data << endl;
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
    int *A, n;
    cout << "Enter the size: ";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    DoublyLL DL(A, n);
    DL.Display();

    return 0;
}