#include <bits/stdc++.h>
using namespace std;

void Match_pal(string p)
{
    string q, r;
    int l, h, i = 0, flag = 1;
    r = p;
    for (i = 0; i < p.size(); i++)
    {
        r += p[i];
        l = 0, h = r.size() - 1;
        while (l < h)
        {
            if (r[l] != r[h])
            {
                flag = 0;
                break;
            }
            else
            {
                l++;
                h--;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    cout << i << endl;
    for (int j = 0; j <= i; j++)
    {
        q += p[j];
    }
    cout << q;
}

int main()
{
    int N;
    string s = "cac";
    Match_pal(s);
}