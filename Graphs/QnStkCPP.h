#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}


// Stack implementation using Template class.
template <class T>
class stack
{
private:
    int size;
    int top;
    T *s;

public:
    stack(int size);
    void push(T x);
    T pop();
    T stacktop();
    int IsEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
};

template <class T>
stack<T>::stack(int size)
{
    top = -1;
    this->size = size;
    s = new T[size];
}

template <class T>
void stack<T>::push(T x)
{
    if (top == size - 1)
    {
        ;
    }
    else
    {
        top++;
        s[top] = x;
    }
}

template <class T>
T stack<T>::pop()
{
    T x = 0;
    if (top == -1)
    {
        ;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

template <class T>
T stack<T>::stacktop()
{
    T x = 0;
    if (top == -1)
    {
        ;
    }
    else
    {
        x = s[top];
    }
    return x;
}