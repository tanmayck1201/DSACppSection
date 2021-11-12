// The TC of all operations is O(1)!
#include <iostream>
using namespace std;

class stack
{
private:
    int size;
    int top;
    int *s;

public:
    stack();
    void push(int x);
    int pop(stack *st);
    int peek(stack st, int pos);
    int stacktop(stack st);
    void display(stack st);
    /*~stack()
    {
        delete[] s;
    }*/
};

stack::stack()
{
    int N;
    cout << "Enter the size of stack: ";
    cin >> size;

    s = new int[size];
    top = -1;

    cout << "No. of elements u want to enter: ";
    cin >> N;

    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        push(s[i]);
    }
}

void stack::push(int x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow!!";
    }
    else
    {
        top++;
        s[top] = x;
        cout << "The element " << x << " has been successfully inserted!!" << endl;
    }
}

int stack::pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack Underflow!!";
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int stack::peek(stack st, int pos)
{
    int x = -1;
    if ((st.top - pos + 1) == -1)
    {
        cout << "Invalid Index!!";
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int stack::stacktop(stack st)
{
    int x = -1;
    if (st.top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        x = st.s[st.top];
    }
    return x;
}

void stack::display(stack st)
{
    if (st.top == -1)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "The stack elements are: " << endl;
        for (int i = 0; i <= st.top; i++)
        {
            cout << st.s[i] << endl;
        }
    }
}

int main()
{
    stack st;
    int choice, n, pos;

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
            cout << "The deleted element is: " << st.pop(&st) << endl;
            break;

        case 3:
            cout << "Enter the position of element: ";
            cin >> pos;
            cout << "The element at position " << pos << " is: " << st.peek(st, pos) << endl;
            break;

        case 4:
            cout << "The topmost element is: " << st.stacktop(st) << endl;
            break;

        case 5:
            st.display(st);
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