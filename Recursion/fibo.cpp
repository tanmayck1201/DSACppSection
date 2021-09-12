#include<iostream>
using namespace std;

class fibo{
    public:
    int fibosoln(int n){
        if(n==0 || n==1){
            return n;
        }
        return fibosoln(n-2) + fibosoln(n-1);
    }
};

int main()
{
    int n;
    fibo obj;
    cout<<"The fibo series is:"<<obj.fibosoln(6)<<endl;
    return 0;
}


// W/O Recursion
/* // Fibonacci Series using Space Optimized Method
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	int a = 0, b = 1, c, i;
	if( n == 0)
		return a;
	for(i = 2; i <= n; i++)
	{
	c = a + b;
	a = b;
	b = c;
	}
	return b;
}

// Driver code
int main()
{
	int n = 1;
	
	cout << fib(n);
	return 0;
}

// This code is contributed by Code_Mech
*/