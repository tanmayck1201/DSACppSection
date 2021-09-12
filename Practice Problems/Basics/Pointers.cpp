/*The function is declared with a void return type, so there is no value to return. 
   Modify the values in memory so that a contains their sum 
   and b contains their absoluted difference.*/
   
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void update(int &a,int &b) {
    // Complete this function 
    int a1,b1;
    a1=a+b;
    b1=abs(a-b);   
    a=a1;
    b=b1;    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b;
    int *pa = &a, *pb = &b;
    
    cin>>a>>b;
    update(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
