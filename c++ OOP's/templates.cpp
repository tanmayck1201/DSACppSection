#include <iostream>
using namespace std;

template <class T>
class DemoT
{
private:
    T a;
    T b;

public:
    DemoT(T a, T b);
    T add();
    T sub();
};

template <class T>
DemoT<T>::DemoT(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T DemoT<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T DemoT<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    DemoT<int> ar(10, 5);
    cout << ar.add() << endl;
    DemoT<float> ar1(10.5, 5.4);
    cout << ar1.sub() << endl;

    return 0;
}