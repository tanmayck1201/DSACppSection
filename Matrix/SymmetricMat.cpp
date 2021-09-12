#include<iostream>
using namespace std;

class Symmetric
{
private:
    int *A, n, x;
public:
    Symmetric(int n);
    void create(int n);
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Symmetric();
};

Symmetric::Symmetric(int n)
{
    this->n = n;
    A = new int[n*(n+1) /2];
}

void Symmetric::create(int n)
{
    this->n = n;
    cout<<"Enter the elements for "<<n<<"x"<<n<<" matrix: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>x;
            set(i,j,x);
        }
    }
}

void Symmetric::set(int i, int j, int x){
    if(i>=j){
        A[i*(i-1)/2 + j-1] = x;
    }else
        A[j * (j - 1) / 2 + i - 1] = x;
}

int Symmetric::get(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2 + j-1];
    }else{
        return A[j * (j - 1) / 2 + i - 1];
    }
}

void Symmetric::display(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << A[(i*(i-1))/2 + (j-1)] << " "; 
            }
            else
            {
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
            }
        }
        cout << endl;
    }
}

Symmetric::~Symmetric()
{
    delete []A;
}

int main()
{
    int n;
    cout<<"Enter the dimension for matrix: ";
    cin>>n;

    Symmetric S1(n);
    S1.create(n);
    //S1.set();
    S1.display();
    cout<<S1.get(3,2)<<endl;
    cout<<S1.get(4,4)<<endl;
    

    return 0;
}