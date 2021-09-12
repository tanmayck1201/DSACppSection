#include<iostream>
using namespace std;

template<class T>
class Rectangle{
    private:
    T length;
    T breadth;

    public:
    Rectangle(){                       //Default constructor
        length=breadth=1;
    }

    Rectangle(T l,T b);          //Parameterized constructor

    T area();

    T perimeter();

    T getLength(){
        return length;
    }

    void setLength(T l){
        length = l;
    }

    ~Rectangle();                     //Destructor
};

template <class T>
Rectangle<T>::Rectangle(T l,T b){
    length = l;
    breadth = b;
}

template <class T>
T Rectangle<T>::area(){
    return length * breadth;
}

template <class T>
T Rectangle<T>::perimeter(){
    return 2 * length * breadth;
}

//Destructor
template <class T>
Rectangle<T>::~Rectangle(){}

//Main Method
int main()
{
    Rectangle<int> r(11,5);
    cout<<r.area()<<endl;
    cout<<r.perimeter()<<endl;
    r.setLength(20);
    cout<<r.getLength()<<endl;
    
    return 0;
}