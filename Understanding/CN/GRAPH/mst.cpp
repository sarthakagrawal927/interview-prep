//Minimum Spanning tree
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1; //remove this in case of directed graphs
        // store weight instead of 1, if weighted graph
    }

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}
