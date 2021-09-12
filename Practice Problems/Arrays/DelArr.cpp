#include<iostream>
using namespace std;

class DeleteArr{
    private:
    int length;
    int size;
    int A[10];

    public:
    DeleteArr();
    void Delete(int index);
    void Display();
};

DeleteArr :: DeleteArr(){
        int n;
        cout << "Enter no. of elements to enter: ";
        cin >> n;

        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        length = n;
}

void DeleteArr :: Delete(int index){
    if(index<=length){
        int x = A[index];
        for (int i = index; i < length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
    }
}

void DeleteArr :: Display(){
    cout<<"The array elements are: \n";
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<<endl;
    }
} 

int main()
{
    DeleteArr del;
    del.Delete(3);
    del.Display();

    return 0;
}