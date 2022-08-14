// https://leetcode.com/problems/valid-palindrome/
// Try above Q with mod in this code!!

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s,p;
    getline(cin, s);
    int i,j;
    int low = 0;
    int flag = 0;
    int high = s.size() - 1;
/*
    for (i = 0, j = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
        if (s[i] >= 97 && s[i] <= 122)
        {
            p[j] = s[i];
            j++;
        }
    }

    int high = p.size() - 1;
*/

    while (low < high)
    {
        if (s[low] != s[high])
        {
            flag = 1;
            break;
        }
        low++;
        high--;
    }

    if (flag == 0)
        cout << "String is palindrome";
    else
        cout << "String is not palindrome";
    return 0;
}
