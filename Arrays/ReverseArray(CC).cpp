#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Rarray{
    public:
    float *A;
    int size=10;
    int l;
    void Display(float A[],int l){
        for (int i = 0; i < l; i++)
    {
        cout<<A[i]<<" ";
    }
    }
    void ReverseArray(float A[],int l);
    void swap(float &x, float &y){
    float t = x;
    x = y;
    y = t;
}
};

void Rarray :: ReverseArray(float A[], int l){
    int i,j;

    for ( i = 0, j=l-1; i<=j; i++,j--)
    {
        swap(A[i],A[j]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Rarray r;
    int n;
    r.A = new float[r.size]; 
    cin>>n;
    
    for (int i=0; i<n; i++) {
    cin>>r.A[i];
    }
    r.l=n;
    
    r.ReverseArray(r.A,r.l);
    r.Display(r.A,r.l);
    return 0;
}
