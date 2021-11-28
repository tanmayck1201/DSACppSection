// Simple Queue with all operations having O(1) time!
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
    void Insert_from_front(int x);
    void Insert_from_rear(int x);
    int Delete_from_rear();
    int Delete_from_front();
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
    front = rear = -1;
}

// Destructor.
Queue::~Queue()
{
    delete[] Q;
}

// check if full
bool Queue::IsFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

// check if empty
bool Queue::IsEmpty()
{
    if (front > rear || (front == -1 && rear == -1))
    {
        return true;
    }
    return false;
}

// Insert in queue from front.
void Queue::Insert_from_front(int x)
{
    // Full from front!
    if ((front == -1 && rear != -1) || front == 0)
    {
        cout << "Queue is full from front!!" << endl;
    }
    else
    {
        // first element going to get insert.
        if (front == -1 && rear == -1)
        {
            front++;
            Q[front] = x;
            rear = front;
            cout << "Successfully Inserted!!" << endl;
        }
        // Any index apart from 0 & 1.
        else if (front != -1 || front != 0)
        {
            front--;
            Q[front] = x;
            cout << "Successfully Inserted!!" << endl;
        }
    }
}

// Insert in queue from rear.
void Queue::Insert_from_rear(int x)
{
    if (IsFull())
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
        cout << "Successfully Inserted!!" << endl;
    }
}

// Delete from queue from rear.
int Queue::Delete_from_rear()
{
    int x = -1;
    if (IsEmpty())
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        if (front == rear)
        {
            x = Q[rear];
            front = rear = -1;
        }
        else
        {
            x = Q[rear];
            rear--;
        }
    }
    return x;
}

// Delete from queue from front.
int Queue::Delete_from_front()
{
    int x = -1;
    if (IsEmpty())
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        x = Q[front];
        front++;
    }
    return x;
}

// Display the queue!
void Queue::display()
{
    if (!IsEmpty())
    {
        cout << "Queue elements are: " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << Q[i] << " ";
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
        cout << "1. Enter the data from Front." << endl;
        cout << "2. Enter the data from Rear." << endl;
        cout << "3. Delete the data from Front." << endl;
        cout << "4. Delete the data from Rear." << endl;
        cout << "5. Display the queue." << endl;
        cout << "6. Exit." << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to push from Front: ";
            cin >> n;
            q.Insert_from_front(n);
            break;

        case 2:
            cout << "Enter the element to push from Rear: ";
            cin >> n;
            q.Insert_from_rear(n);
            break;

        case 3:
            cout << "The deleted element from Front is: " << q.Delete_from_front() << endl;
            break;

        case 4:
            cout << "The deleted element from Rear is: " << q.Delete_from_rear() << endl;
            break;

        case 5:
            q.display();
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