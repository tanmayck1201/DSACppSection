// Simple Queue with all operations having O(1) time!
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

// Default Constructor
Queue::Queue()
{
    front = rear = 0;
}

// Destructor.
Queue::~Queue()
{
    Node *p = front;
    while (front)
    {
        front = front->next;
        delete p;
        p = front;
    }
}

// Insert in queue from rear.
void Queue::enqueue(int x)
{
    Node *t;
    t = new Node;
    if (t == 0)
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        t->data = x;
        t->next = 0;
        if (front == 0)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
        cout << "Successfully Inserted!!" << endl;
    }
}

// Delete from queue from front.
int Queue::dequeue()
{
    int x = -1;
    Node *p;
    if (front == 0)
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Display the queue!
void Queue::display()
{
    Node *p = front;
    if (front != 0)
    {
        cout << "Queue elements are: " << endl;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Queue is empty!!" << endl;
    }
}

// Main function
int main()
{
    Queue q;
    int choice, n, x;

    /*cout << "Enter the elements: ";
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        q.enqueue(x);
    }*/

    do
    {
        cout << "1. Enter the data." << endl;
        cout << "2. Delete the data." << endl;
        cout << "3. Display the queue." << endl;
        cout << "4. Exit." << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> n;
            q.enqueue(n);
            break;

        case 2:
            cout << "The deleted element is: " << q.dequeue() << endl;
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Thank You!!";
            break;

        default:
            cout << "Wrong Input!!" << endl;
        }
    } while (choice != 4);

    return 0;
}