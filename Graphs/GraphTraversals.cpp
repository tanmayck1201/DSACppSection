// Graph traversals using BFS & DFS!
#include <iostream>
#include "QnStkCPP.h"

using namespace std;

void BFS(int **G, int start, int n)
{
    int i = start;
    int *visited;
    visited = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }

    cout << "BFS: " << i << " ";
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 1; j <= n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int *visit(int n)
{
    int *visited = new int[n];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
    return visited;
}

void DFS(int **G, int start, int n, int visited[])
{
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for (int j = 1; j <= n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n, visited);
            }
        }
    }
}

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

    BFS(A, 4, n);
    int *visited = visit(n);
    cout << endl;
    cout << "DFS: ";
    DFS(A, 4, n, visited);

    return 0;
}