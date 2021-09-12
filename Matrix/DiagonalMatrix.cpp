#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int *A, n;

public:
    DiagonalMatrix(int n)
    {
        this->n = n;   
        A = new int(n);
    };
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();

    ~DiagonalMatrix();
};

void DiagonalMatrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[j - 1] = x;
    }
}

int DiagonalMatrix::get(int i, int j)
{
    if (i == j)
    {
        return A[j - 1];
    }
    return 0;
}

void DiagonalMatrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

DiagonalMatrix::~DiagonalMatrix()
{
    delete[] A;
}

int main()
{
    DiagonalMatrix DM(4);
    DM.set(1, 1, 5);
    DM.set(2, 2, 6);
    DM.set(3, 3, 7);
    DM.set(4, 4, 8);
    DM.display();

    return 0;
}