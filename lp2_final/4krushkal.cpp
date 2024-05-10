#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void KrushkalMst(vector<Edge> edges, int V)
{
    vector<Edge> result(V);
    vector<int> parent(V, -1);

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    int e = 0, i = 0;
    while (e < V - 1 && i < edges.size())
    {
        Edge next_edges = edges[i++];

        int x = find(parent, next_edges.src);
        int y = find(parent, next_edges.dest);

        if (x != y)
        {
            result[e++] = next_edges;
            Union(parent, x, y);
        }
    }
    int minCost = 0;
    cout << "\n Minimum Spanning Tree For Krushkal"<<endl;
    for (int i = 0; i < e; ++i)
    {
        cout << result[i].src << "--->" << result[i].dest << "==" << result[i].weight << endl;
        minCost += result[i].weight;
    }
    cout << "\nMinimum Cost: " << minCost;
}

int main()
{
    int V, E;
    cout << "Enter the No.of vertices and Edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "\nEnter The src,dest,weight for each edges: \n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    KrushkalMst(edges, V);
}
