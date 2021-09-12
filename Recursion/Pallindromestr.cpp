#include<iostream>
using namespace std;

bool Ispallindrome(string &str, int start, int end){
    if(start>=end){
        return true;
    }
    return (str[start]==str[end] && Ispallindrome(str,start+1,end-1));
}


int main()
{
    string s = "abcba";
    if(Ispallindrome(s, 0, s.length() - 1)){
        cout<<"Yes!";
    }
    else{
        cout<<"NO!!";
    }
    return 0;
}

