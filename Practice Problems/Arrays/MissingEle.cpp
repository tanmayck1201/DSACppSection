#include <iostream>
using namespace std;

class MissingEle
{
private:
    int diff, n, l, h;
    int *A;

public:
    MissingEle();
    void MissElement();
};

MissingEle ::MissingEle()
{
    A = new int[12];
    cout << "Enter the no. of elements to enter: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    l = A[0];
    h = A[n - 1];
    diff = l - 0;
}

void MissingEle ::MissElement()
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {
            // Single Missing Element
            /*cout<<"Missing Element is: "<<(i + diff);
            break;*/

            // Multiple Missing Elements
            while (diff < (A[i] - i))
            {
                cout << "Missing Elements are: " << (i + diff) << endl;
                diff++;
            }
        }
    }
}

int main()
{
    MissingEle M1;
    M1.MissElement();

    return 0;
}