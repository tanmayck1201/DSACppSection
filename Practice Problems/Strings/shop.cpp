// TCS-NQT que. - Shopkeeper.....
// (find here 2nd que https://www.youtube.com/watch?v=eDOIGqlom6Y&list=PL3JmT-xgOMNy5r3QBTRzv32LFUTXBmKf2&index=2&t=718s)
#include <bits/stdc++.h>
using namespace std;

int price_pdct(string s)
{
    int price = 0, a;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            // Just S[i] will return ASCII value of digit!
            // So, minus this ['0'(48)]
            price += (s[i] - '0');
        }
        else
        {
            // for non-digits.
            int max = 0;
            // typecasting
            a = int(s[i]);
            // max digit in a number
            while (a != 0)
            {
                if ((a % 10) > max)
                {
                    max = a % 10;
                }
                a = a / 10;
            }
            price += max;
        }
    }
    // final price
    return price;
}

int main()
{
    string str;

    cout << "Enter the string: ";
    getline(cin, str);

    cout << price_pdct(str) << endl;

    return 0;
}
