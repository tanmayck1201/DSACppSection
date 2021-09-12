//Initial Template for C++
#include <iostream>
using namespace std;


class Solution{
  public:
    //Complete this function
    int RecursivePower(int n,int p)
    {
        if(p==0){
            return 1;
        }
        return RecursivePower(n,p-1) * n;
    }
};


int main()
{
	    int n,p;
	    
	    //taking n and p as inputs
	    cin>>n>>p;
	    
	    //calling RecursivePower() function
	    Solution obj;
	    cout<<obj.RecursivePower(n,p)<<endl;
    	return 0;
}  