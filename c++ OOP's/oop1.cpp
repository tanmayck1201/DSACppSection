#include<iostream>
using namespace std;

class Student{
    int a,b;
    public:
    int c,d;
    void setdata(int a1, int b1);
    void getdata(){
        cout<<"The value of a is: "<<a<<endl;
        cout<<"The value of b is: "<<b<<endl;
        cout<<"The value of c is: "<<c<<endl;
        cout<<"The value of d is: "<<d<<endl;
    }
};

void Student :: setdata(int a1, int b1)
{
    a=a1;
    b=b1;
    //Nesting of member functions.
    //getdata();
}

int main()
{
    Student s;
    s.c=6;
    s.d=7;
    s.setdata(4,5);
    s.getdata();
    
    return 0;
}