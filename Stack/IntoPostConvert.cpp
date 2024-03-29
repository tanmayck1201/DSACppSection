#include <iostream>
#include <cstring>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char *s;
    stack();
    void push(int x);
    char pop();
    bool IsEmpty();
    bool IsFull();
    char stacktop();
    int IsOperand(char x);
    int Precedence(char x);
    char *ConvertToPostfix(char *infix);
};

stack::stack()
{
    top = -1;
}

void stack::push(int x)
{
    if (IsFull())
    {
        cout << "Stack Overflow!!";
    }
    else
    {
        top++;
        s[top] = x;
    }
}

char stack::pop()
{
    char x;
    if (IsEmpty())
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

bool stack::IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::IsFull()
{
    if (top >= (size - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char stack::stacktop()
{
    char x;
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

// Check if character is operand or not!
int stack::IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Deciding precedence of operators.
int stack::Precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    return 0;
}

char *stack::ConvertToPostfix(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    // Traverse whole expression
    while (infix[i] != '\0')
    {
        // If it's operand just push it to postfix array & increment pointer.
        if (IsOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        // for operator
        else
        {
            // If operator precedence is greater than existing top then push!
            if (Precedence(infix[i]) > Precedence(s[top]))
            {
                push(infix[i++]);
            }
            // if its reverse then pop out element & insert in postfix array.
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    // After EOE pop all from stack & insert to postfix array!
    while (!IsEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    stack st;
    char *infix;
    infix = new char[20];

    cout << "Enter the expression: ";
    gets(infix);

    st.size = strlen(infix);
    st.s = new char[st.size];

    cout << "The Postfix expression is: " << st.ConvertToPostfix(infix) << endl;

    return 0;
}
