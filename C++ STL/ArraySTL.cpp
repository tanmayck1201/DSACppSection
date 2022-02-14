#include <iostream>
#include <array>
using namespace std;

//STL array acts as static array.
int main()
{
    int traditional[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    cout << "Element at 2nd Index-> " << a.at(2) << endl;
    cout << "Empty or not" << a.empty() << endl;

    cout << a.front() << endl;
    cout << a.back() << endl;

    return 0;
}