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
    int pop();
    int peek(int pos);
    int stacktop();
    void display();
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

int stack::pop()
{
    int x = -1;
    if (top == -1)
    {
        cout << "Stack Underflow!!";
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int stack::peek(int pos)
{
    int x = -1;
    if ((top - pos + 1) == -1)
    {
        cout << "Invalid Index!!";
    }
    else
    {
        x = s[top - pos + 1];
    }
    return x;
}

int stack::stacktop()
{
    int x = -1;
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        x = s[top];
    }
    return x;
}

void stack::display()
{
    if (top == -1)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << "The stack elements are: " << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << s[i] << endl;
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
            cout << "The deleted element is: " << st.pop() << endl;
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