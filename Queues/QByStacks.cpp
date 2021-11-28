// The TC of all operations is O(1)!
#include <iostream>
#include <stack>
using namespace std;

class QueueByStack
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    QueueByStack();
    ~QueueByStack();
    void enqueue(int x);
    int dequeue();
    void display();
};

void QueueByStack::enqueue(int x)
{
    s1.push(x);
    cout << "Successfully Inserted!!" << endl;
}

int QueueByStack::dequeue()
{
    int x = -1;
    if (s2.empty())
    {
        if (s1.empty())
        {
            cout << "Queue is Empty";
            return x;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    x = s2.top();
    s2.pop();
    return x;
}

void QueueByStack::display()
{
    if (s1.top() != -1 && s2.top() != -1)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        for (int i = s2.top(); i <= 0; i++)
        {
            //cout<< s2[i] << " ";
        }
    }
}

int main()
{
    QueueByStack q;
    int choice, n, m, pos;

    do
    {
        cout << "1. Enter the data." << endl;
        cout << "2. Delete the data." << endl;
        //cout << "3. Peek in the qack." << endl;
        //cout << "4. Get Top element in the qack." << endl;
        cout << "3. Display the qack." << endl;
        cout << "4. Exit." << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> n;
            q.enqueue(n);
            break;

        case 2:
            m = q.dequeue();
            cout << "The deleted element is: " << m << endl;
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