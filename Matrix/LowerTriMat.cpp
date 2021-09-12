#include<iostream>
using namespace std;
 
class LowerTriMat
{
private:
    int *A,n;
public:
    int x;
    LowerTriMat(int n);
    ~LowerTriMat();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
}; 
 
 
LowerTriMat::LowerTriMat(int n)
{
    A = new int((n*(n+1))/2); 
    this->n=n; //changes
 
    cout<<"Enter the elements: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>x;
            //Function Call 
            set(i,j,x);
        }    
    }
    cout<<endl;
 
    //Function call
    display();
}
 
void LowerTriMat::set(int i, int j,int x){
    if(i>=j)
        A[(i*(i-1))/2 + (j-1)] = x; //changes
}
 
int LowerTriMat::get(int i, int j){
    if(i>=j)
        return A[(i*(i-1))/2 + (j-1)]; //changes
    return 0;
}
 
void LowerTriMat::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << A[(i*(i-1))/2 + (j-1)] << " "; //changes
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
 
LowerTriMat::~LowerTriMat()
{
    delete []A;
}
 
int main()
{
    int n;
    cout<<"Enter the dimensions for matrix: ";
    cin>>n;
 
    LowerTriMat L1(n);
 
    return 0;
}