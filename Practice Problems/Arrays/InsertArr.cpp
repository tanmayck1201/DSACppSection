#include <iostream>
using namespace std;

template <class T>
class Insertion
{
private:
    T A[10];
    T size;
    T length;
    T n;
    T index, element;

public:
    Insertion()
    {
        size = 10;
        cout << "Enter no. of elements to enter: ";
        cin >> n;

        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        length = n;
    };

    void Append(T x);
    void InsertArr(T index, T element);
    void Display();
};

template <class T>
void Insertion<T>::Append(T x)
{
    if (length < size)
    {
        A[length] = x;
        A[length++];
    }
}

template <class T>
void Insertion<T>::InsertArr(T index, T element)
{
    if(index>=0 && index<=length){
        for (int i = length; i < index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = element;
        A[length++];
    }

}

template <class T>
void Insertion<T>::Display()
{
    cout<<"The array elements are: \n";
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    }
}


int main()
{
    Insertion<int> apd;
    apd.Append(265);
    apd.InsertArr(3,25);
    apd.Display();

    return 0;
}