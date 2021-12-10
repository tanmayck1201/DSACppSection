// Circular Queue with all operations having O(1) time!
#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool IsFull();
    bool IsEmpty();
    void display();
};

// Default Constructor
Queue::Queue()
{
    cout << "Enter the size of queue: ";
    cin >> size;
    Q = new int[size];
    front = rear = 0;
}

// Destructor.
Queue::~Queue()
{
    delete[] Q;
}

// check if full
bool Queue::IsFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    return false;
}

// check if empty
bool Queue::IsEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

// Insert in queue from rear.
void Queue::enqueue(int x)
{
    if (IsFull())
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
        cout << "Successfully Inserted!!" << endl;
    }
}

// Delete from queue from front.
int Queue::dequeue()
{
    int x = -1;
    if (IsEmpty())
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

// Display the queue!
void Queue::display()
{
    if (!IsEmpty())
    {
        cout << "Queue elements are: " << endl;
        int i = (front + 1);
        while (i != (rear + 1) % size)
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
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