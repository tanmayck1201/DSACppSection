#include<iostream>
using namespace std;

int fun1(int n){
    if(n>0){
        cout<<n<<endl;
        fun1(n-1);
        cout<<n<<endl;
    }
    return 0;
}

int main()
{
    int x=5;
    fun1(x);

    return 0;
}