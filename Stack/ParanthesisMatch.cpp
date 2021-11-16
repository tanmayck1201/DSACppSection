#include <iostream>
#include <cstring>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char *s;
    bool b = true;
    stack();
    void push(int x);
    char pop();
    bool IsEmpty();
    bool IsFull();
    bool Isbalance(char *exp);
    bool Arepair(char o, char c);
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

bool stack::Arepair(char o, char c)
{
    if (o == '(' && c == ')')
    {
        return true;
    }
    else if (o == '{' && c == '}')
    {
        return true;
    }
    else if (o == '[' && c == ']')
    {
        return true;
    }
    return false;
}

bool stack::Isbalance(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (IsEmpty())
            {
                return false;
            }
            char a = pop();
            cout << a << endl;
            cout << exp[i] << endl;
            if (b)
            {
                b = Arepair(a, exp[i]);
            }
        }
    }
    return IsEmpty() ? true : false;
}

int main()
{
    stack st;
    char exp[20];
    cout << "Enter the expression to check: ";
    gets(exp);

    st.size = strlen(exp);
    st.s = new char[st.size];

    bool s = st.Isbalance(exp);
    if (s == true && st.b == true)
    {
        cout << "The expression is well balanced with proper format!!";
    }
    else if (s == true && st.b == false)
    {
        cout << "The expression is balanced but not in proper format!!";
    }
    else
    {
        cout << "The expression is not balanced!!";
    }

    return 0;
}