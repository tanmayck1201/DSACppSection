#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLL
{
private:
    Node *head, *tail;

public:
    CircularLL()
    {
        head = NULL;
        tail = NULL;
    };
    CircularLL(int *A, int n);
    ~CircularLL();

    void Display();
};

CircularLL ::CircularLL(int *A, int n)
{
    Node *t, *tail;
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

void CircularLL ::Display()
{
    Node *p = head;
    cout << "The elements are: " << endl;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

/* Recursive display, have to make some changes in pgm to make it run!
void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}*/

CircularLL ::~CircularLL()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
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

    CircularLL CL(A, n);
    CL.Display();

    return 0;
}