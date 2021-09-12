#include <iostream>
using namespace std;

// Forward Declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int SumRComplex(Complex, Complex);
    int SumCComplex(Complex, Complex);
};

class Complex
{
    int a, b;

public:
    // Individually declaring functions as friends
    // friend int Calculator ::SumRComplex(Complex, Complex);
    // friend int Calculator ::SumCComplex(Complex, Complex);

    // Aliter: Declaring the entire Calculator class as friend
    friend class Calculator;
    void setnumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printnumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int Calculator ::SumRComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::SumCComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex c1, c2, sum;
    c1.setnumber(3, 4);
    c1.printnumber();
    c2.setnumber(5, 6);
    c2.printnumber();

    Calculator calc;
    int res = calc.SumRComplex(c1, c2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.SumCComplex(c1, c2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;
    return 0;
}