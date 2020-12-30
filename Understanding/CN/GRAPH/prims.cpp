//Minimum Spanning tree =
// Spanning tree (tree (connecting + non-cyclic) + all graph vertex selected) + least weighted
// n vertexes , n -1  edges
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class Vertex
{
public:
    bool isVisited;
    int parent, weight;

    Vertex()
    {
        isVisited = 0;
        weight = INT_MAX;
        parent = -1;
    }
};

int findMinVertex(Vertex *v, int n)
{
    int min = -1;
    int wt = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!v[i].isVisited && (min == -1 || v[min].weight > v[i].weight))
        {
            min = i;
        }
    }
    v[min].isVisited = 1;
    return min;
}

void prim(int **edges, int n)
{
    Vertex *V = new Vertex[n];
    V[0].parent = -1;
    V[0].weight = 0;
    for (int i = 0; i < n - 1; i++)
    {
        //Find min Vertex
        int minVertex = findMinVertex(V, n);

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !V[j].isVisited)
            {
                if (edges[minVertex][j] < V[j].weight)
                {
                    V[j].weight = edges[minVertex][j];
                    V[j].parent = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (V[i].parent < i)
        {
            cout << V[i].parent << " " << i << " " << V[i].weight << endl;
        }
        else
        {
            cout << i << " " << V[i].parent << " " << V[i].weight << endl;
        }
    }

    delete[] V;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Vertex *inp = new Vertex[n];

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        edges[first][second] = weight;
    }

    prim(edges, n);

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;

    return 0;
}
