// Graph representation & traversals using Adjacency List.
#include <iostream>
#include "QnStkCPP.h"
using namespace std;

class Node1
{
public:
    int data;
    Node1 *next;

    Node1 *SearchLL(Node1 *p, int key);
    Node1 **Create(int vertices);
    void Place(Node1 **adj, int x, int y);
    void BFS(Node1 **G, int start, int n);
};

// Creating array of pointers of type node.(Another method for double pointer!)
Node1 **Node1::Create(int vertices)
{
    // creating node pointers of vertices(if v=7, node pointers=7[starting from 0])
    // allocating node pointers to array of pointers of type node
    // Node array is created by double pointer as it's storing addresses of node pointers.
    Node1 **adj = new Node1 *[vertices + 1];
    for (int i = 0; i <= vertices; i++)
    {
        // Make all node pointers as null.
        adj[i] = 0;
    }
    // returning array of node pointers now!
    return adj;
}

// placing the edges correctly in adjacency list.
void Node1::Place(Node1 **adj, int x, int y)
{
    // y is edge here & x is vertex.
    Node1 *temp = new Node1;
    temp->data = y;
    temp->next = 0;

    // if it's first time to insert in vertex/node pointer!
    if (!adj[x])
    {
        adj[x] = temp;
    }
    // To insert last in list of that vertex & link it.
    else
    {
        Node1 *ptr = adj[x];
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

// BFS traversal
void Node1::BFS(Node1 **G, int start, int n)
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
        Node1 *p = G[i];
        // print all nodes(non-visited) of that vertex.
        while (p != 0)
        {
            if (visited[p->data] == 0)
            {
                cout << p->data << " ";
                visited[p->data] = 1;
                enqueue(p->data);
            }
            p = p->next;
        }
    }
}

int main()
{
    Node1 N;
    int n, t, edges;
    cout << "Enter the no. of vertices: ";
    cin >> n;
    Node1 **G = N.Create(n);

    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Now enter these " << edges << " edges in the form of (v e) as 1-based index vertex: " << endl;

    int x, y;
    while (edges--)
    {
        cin >> x >> y;
        N.Place(G, x, y);
    }

    cout << "How many BFS traversals? ";
    cin >> t;
    while (t--)
    {
        cout << "Enter the starting vertex: ";
        int start;
        cin >> start;
        N.BFS(G, start, n);
        cout << endl;
    }

    return 0;
}