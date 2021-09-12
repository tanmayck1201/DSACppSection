#include <iostream>
using namespace std;

class Point
{
    int a, b;

public:
    Point(int, int);

    void printdata()
    {
        cout << "The points are " << a << "&" << b << endl;
    }
};

Point::Point(int x, int y)
{
    a=x;
    b=y;
}

int main()
{
    Point a(2,3);
    Point b(8,9);
    a.printdata();
    b.printdata();

    return 0;
}