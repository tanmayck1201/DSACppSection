// Graph traversals using BFS & DFS!
#include <iostream>
#include "QnStkCPP.h"

using namespace std;

// BFS traversal
void BFS(int **G, int start, int n)
{
    int i = start;
    // visited array - elements that are printed.
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
        // dequeue element to explore it furthure!
        i = dequeue();
        for (int j = 1; j <= n; j++)
        {
            // traverse all colmns of that vertex element.
            if (G[i][j] == 1 && visited[j] == 0)
            {
                // if edge find & not visited till now do -
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

// DFS traversal using recursion
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
                // this call will break loop exec for current vertex
                // & will start exploring futhure as per dfs algo
                DFS(G, j, n, visited);
                // while returning call loop will complete & if any
                // elements are still not done, will visit it!
            }
        }
    }
}

// dfs using stack
void dfsstack(int **G, int start, int n)
{
    int u = start;
    int *visited = new int[n];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
    stack<int> stk(15);
    stk.push(u);

    while (!stk.IsEmpty())
    {
        u = stk.stacktop();
        stk.pop();

        // condition will execute for those vertexes
        // who have not done till now
        if (visited[u] != 1)
        {
            cout << u << " " << flush;
            visited[u] = 1;

            for (int v = n; v >= 0; v--)
            {
                if (G[u][v] == 1 && visited[v] == 0)
                {
                    // will push every ele on stack
                    // be it there before existing in stack
                    // but while exec only non-visited vertex will exec loop & all!
                    stk.push(v);
                }
            }
        }
    }
}

int main()
{
    int **A, n, edges, p;
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

    cout << "Enter starting vertex: ";
    cin >> p;

    BFS(A, p, n);
    int *visited = visit(n);
    cout << endl;
    cout << "DFS: ";
    DFS(A, p, n, visited);
    cout << "\nDFS by Stack: ";
    dfsstack(A, p, n);

    return 0;
}
