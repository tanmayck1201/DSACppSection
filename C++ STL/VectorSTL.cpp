#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    // a vector of predefined size
    vector<int> a(5, 1);
    // a vector pastes contents & size to newly created vector
    vector<int> last(a);

    cout << "print a" << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "print last" << endl;
    for (int i : last)
    {
        cout << i << " ";
    }
    cout << endl;

    // Capacity - memory allocated
    cout << "Capacity: " << a.capacity() << endl;
    // Size of an array (contents contain)
    cout << "Size: " << a.size() << endl;

    // v.back,front,at() - operations present.

    return 0;
}