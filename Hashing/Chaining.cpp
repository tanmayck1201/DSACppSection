// Hashing pgm of open addressing->Chaining (works like adjacency list)
// Give attention to how array/pointers are created & passed thr' function! [IMP Pgm]
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void InsertInSort(Node **HT, int x);
    Node *SearchLL(Node *p, int key);
    int hash(int key);
    void Insert(Node *HT[], int key);
};

void Node::InsertInSort(Node **HT, int x)
{
    Node *t, *p, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    p = *HT;
    if (*HT == NULL)
    {
        *HT = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *HT)
        {
            t->next = *HT;
            *HT = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
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

// Hash function to allote proper index.
int Node::hash(int key)
{
    return key % 10;
}

void Node::Insert(Node *HT[], int key)
{
    int index = hash(key);
    // Passing address of index pointer.
    InsertInSort(&HT[index], key);
}

int main()
{
    Node N;
    int n, m;
    // Another way to declare a double pointer
    Node *HT[10];
    Node *temp;

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    cout << "Enter the no. of keys to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        // Passing entire array of pointers & key element.
        N.Insert(HT, m);
    }

    cout << "Enter the element to search: ";
    cin >> m;

    // Passing address of specific(search element) pointer.
    temp = N.SearchLL(HT[N.hash(m)], m);
    if (temp == 0)
    {
        cout << "Element not found!!";
    }
    else
    {
        cout << "Element found!!";
    }

    return 0;
}
