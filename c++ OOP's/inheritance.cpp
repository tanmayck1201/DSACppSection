#include<iostream>
using namespace std;


class A{
    int a,b;
    public:
    int i=1;
    void setdata(int x, int y){
        a=x;
        b=y;
    }
    void print(){
        cout<<"It'll be successfully executed!!";
    }
};

class B : public A{
    int c;
    public:
    void P(){
        cout<<"The value is: "<<i;
    }
};


int main()
{
    A e;
    B f;
    f.setdata(4,5);
    f.print();
    f.P();
    return 0;
}


