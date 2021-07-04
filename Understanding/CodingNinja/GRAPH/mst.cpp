//Minimum Spanning tree =
// Spanning tree (tree (connecting + non-cyclic) + all graph vertex selected) + least weighted
// n vertexes , n -1  edges
#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src, dst, weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int *parent, int v) // O(V)
{
    if (parent[v] == v)
        return v;

    findParent(parent, parent[v]);
}

void kruskals(Edge *inp, int n, int E) // Net ElogE + EV
{
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(inp, inp + E, compare); // O(E log(E))
    Edge *output = new Edge[n - 1];
    int count = 0, i = 0;
    while (count != n - 1) // O(E)
    {
        Edge currentEdge = inp[i]; //Edge with min weight

        //Safe to add in MST or not
        int sourceParent = findParent(parent, currentEdge.src);
        int destParent = findParent(parent, currentEdge.dst);

        if (sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].src > output[i].dst)
            cout << output[i].dst << " " << output[i].src << " " << output[i].weight << "\n";
        else
            cout << output[i].src << " " << output[i].dst << " " << output[i].weight << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *inp = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int s, d, weight;
        cin >> s >> d >> weight;
        inp[i].src = s;
        inp[i].dst = d;
        inp[i].weight = weight;
    }

    kruskals(inp, n, e);
    cout << "\n\n";
    /*
    ! Will be using 1 D array

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

        for (int i = 0; i < n; i++)
            delete[] edges[i];
        delete[] edges;
   * Kruskal's Algrorithms - to make mst
    Pick lowest weight edge and keep making sure introducing the edge will not result in cycle
    Checking for cycle - check for existing path between vertices

   *  Union Find- Cycle Check Algorithm
    Maintain a parents table, which has a location of the parent (connected point) , common parent vertexes won't be connected

    TODO: Union By rank & Path Compression -> avoid O(V) in finding parent
    ! Net E.logE + E.logV = E.log(EV)
*/

    return 0;
}
