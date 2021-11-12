// The TC of all operations is O(1)!
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stackusingLL
{
public:
    Node *top;
    stackusingLL();
    void push(int x);
    int pop();
    int peek(int pos);
    int stacktop();
    void display();
    ~stackusingLL();
};

stackusingLL::~stackusingLL()
{
    Node *p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

stackusingLL::stackusingLL()
{
    int n, size, *s;
    cout << "Enter the size of stack: ";
    cin >> size;

    s = new int[n];
    top = 0;

    cout << "No. of elements u want to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        push(s[i]);
    }
}

void stackusingLL::push(int x)
{
    Node *t = new Node;
    if (t == 0)
    {
        cout << "Stack Overflow!!";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
        cout << "The element " << x << " has been successfully inserted!!" << endl;
    }
}

int stackusingLL::pop()
{
    int x = -1;
    Node *t;
    if (top == 0)
    {
        cout << "Stack Underflow!!" << endl;
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int stackusingLL::peek(int pos)
{
    Node *p = top;
    for (int i = 0; i < (pos - 1) && p; i++)
    {
        p = p->next;
    }
    if (p)
        return p->data;
    else
        return -1;
}

int stackusingLL::stacktop()
{
    if (top)
        return top->data;
    else
        return -1;
}

void stackusingLL::display()
{
    if (top == 0)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        Node *ptr = top;
        cout << "The stack elements are: " << endl;
        while (ptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

int main()
{
    Node N;
    stackusingLL st;
    int choice, n, m, pos;

    do
    {
        cout << "1. Push the data." << endl;
        cout << "2. Pop the data." << endl;
        cout << "3. Peek in the stack." << endl;
        cout << "4. Get Top element in the stack." << endl;
        cout << "5. Display the stack." << endl;
        cout << "6. Exit." << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> n;
            st.push(n);
            break;

        case 2:
            m = st.pop();
            cout << "The deleted element is: " << m << endl;
            break;

        case 3:
            cout << "Enter the position of element: ";
            cin >> pos;
            cout << "The element at position " << pos << " is: " << st.peek(pos) << endl;
            break;

        case 4:
            cout << "The topmost element is: " << st.stacktop() << endl;
            break;

        case 5:
            st.display();
            break;

        case 6:
            cout << "Thank You!!";
            break;

        default:
            cout << "Wrong Input!!" << endl;
        }
    } while (choice != 6);

    return 0;
}