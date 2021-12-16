// BT Creation & displaying using all 3 traversals [RECURSIVE APPROACH]
#include <iostream>
#include "QnStkCPP.h"

using namespace std;

class Tree
{
public:
    void Preorder(Node *root);
    void Postorder(Node *root);
    void Inorder(Node *root);
    void Levelorder(Node *p);
    int SearchInorder(int inArray[], int inStart, int inEnd, int data);
    Node *GenerateTreeFromTraversals(int *inorder, int *preorder, int inStart, int inEnd);
};

// Preorder function
void Tree::Preorder(Node *p)
{
    stack<Node *> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop();
            p = p->rchild;
        }
    }
}

// Inorder function
void Tree::Inorder(Node *p)
{
    stack<Node *> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

// Postorder function
void Tree::Postorder(Node *p)
{
    long int temp;
    stack<long int> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            st.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = st.pop();
            if (temp > 0)
            {
                st.push(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
    }
}

// LevelOrder function
void Tree::Levelorder(Node *p)
{
    Queue q(20);
    cout << p->data << " ";
    q.enqueue(p);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::SearchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Node *Tree ::GenerateTreeFromTraversals(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return nullptr;
    }

    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }

    int splitIndex = SearchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = GenerateTreeFromTraversals(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = GenerateTreeFromTraversals(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

// Main function
int main()
{
    Tree t;
    int *inorder, *preorder, n;
    cout << "Enter size of i/p Preorder & Inorder: ";
    cin >> n;

    inorder = new int[n];
    preorder = new int[n];

    // int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    // int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    cout << "Enter Preorder for tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    cout << "Enter Inorder for tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    Node *T = t.GenerateTreeFromTraversals(inorder, preorder, 0, n - 1);

    cout << "\nThe Preorder is: "
         << "\n";
    t.Preorder(T);
    cout << "\nThe Inorder is: "
         << "\n";
    t.Inorder(T);
    cout << "\nThe Postorder is: "
         << "\n";
    t.Postorder(T);
    cout << "\nThe Levelorder is: "
         << "\n";
    t.Levelorder(T);

    return 0;
}
