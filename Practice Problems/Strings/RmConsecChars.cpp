/* 
https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
Remove Consecutive chars

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
       string P ="";
        // P += S[0];
        for(int i=1;i<S.length();i++){
            if(S[i]!=S[i-1]){
                P += S[i];
            }
        }
        return P;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends

*/