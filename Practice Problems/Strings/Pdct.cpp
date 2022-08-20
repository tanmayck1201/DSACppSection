// Pgm to find pdct of all digits in a number. (TCS-NQT)
#include <bits/stdc++.h>
using namespace std;

int pdct(int n)
{
    int pdct = 1, a;
    // max digit in a number
    while (n != 0)
    {
        pdct *= n % 10;
        n = n / 10;
    }
    return pdct;
}

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << pdct(n) << endl;

    return 0;
}
