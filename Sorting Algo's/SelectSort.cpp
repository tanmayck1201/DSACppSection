#include <iostream>
#include <vector>
using namespace std;

template <class T>
// function call by 'Call by Reference' Method!(for vectors)
void SelectionSort(vector<T> &vec, int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = k = i; j < n; j++)
        {
            if (vec[j] < vec[k])
            {
                k = j;
            }
        }
        swap(vec[i], vec[k]);
    }
}

template <class T>
void Display(vector<T> &vec, int n)
{
    cout << "The sorted elements are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    vector<float> vec(20);
    int n;
    cout << "Enter the no. of elements u want to enter: ";
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    SelectionSort(vec, n);
    Display(vec, n);
    return 0;
}