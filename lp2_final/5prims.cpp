#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cout << "\nEnter Vertices and Edges:";
    cin >> n >> e;

    int costMat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            costMat[i][j] = INT32_MAX;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cout << "\nEnter the src,dest and weight(u v weight):";
        cin >> u >> v >> weight;
        costMat[u][v] = weight;
        costMat[v][u] = weight;
    }

    int visit[n] = {0};
    int parent[n];
    int minCost = 0;

    int current = 0;
    visit[current] = 1;
    for (int count = 0; count < n - 1; count++)
    {
        int min = INT32_MAX;
        int next = 0;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == 0 && costMat[current][j] < min)
            {
                min = costMat[current][j];
                next = j;
            }
        }
        parent[next] = current;
        visit[next] = 1;
        current = next;
        minCost += min;
    }

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "-->" << i << costMat[parent[i]][i] << endl;
    }
    cout << "\nEnter Minimum Cost:" << minCost << endl;
    return 0;
}