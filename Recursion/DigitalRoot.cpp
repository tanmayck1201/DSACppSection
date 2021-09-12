
#include <iostream>
using namespace std;


int digitalRoot(int n)
{
    //Your code here
    if (n != 0)
    {
        n = (n % 10 + digitalRoot(n / 10));
    }
    if (n > 9)
    {
        n = digitalRoot(n);
    }
    return n;
}



int main()
{
    int n;

    cout<<"Enter the number: ";
    cin >> n; //taking number n

    //calling digitalRoot() function
    cout << digitalRoot(n);

    return 0;
} 