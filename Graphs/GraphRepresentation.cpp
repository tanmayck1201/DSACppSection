// Graph representation using Adjacency Matrix.
#include <iostream>
using namespace std;

int main()
{
    int **A, n, edges;
    cout << "Enter the no. of vertices: ";
    cin >> n;

    // creating int array of pointers
    A = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        A[i] = new int[n];
    }

    for (int i = 0; i <= n; ++i)
    { // for each row(each pointer)
        for (int j = 0; j <= n; ++j)
        { // for each column(each index of array)
            A[i][j] = 0;
        }
    }

    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Now enter these " << edges << " edges in the form of (v e) as 1-based index vertex: " << endl;

    int x, y;
    while (edges--)
    {
        cin >> x >> y;
        A[x][y] = 1;
    }

    for (int i = 0; i <= n; ++i)
    { // for each row(each pointer)
        for (int j = 0; j <= n; ++j)
        { // for each column(each index of array)
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}