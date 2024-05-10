#include <iostream>
#include <vector>
using namespace std;

const int INF = INT32_MAX;

void dijikstra(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 | dist[j] < dist[u]))
            {
                u = j;
            }
        }
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && graph[u][v] + dist[u] < dist[v])
            {
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INF)
        {
            cout << dist[i] << "\n";
        }
        else
        {
            cout << "unreachable\n";
        }
    }
}

int main()
{

    vector<vector<int>> graph = {
        {0, 4, 5, 0, 0},
        {4, 0, 0, 2, 0},
        {5, 9, 0, 6, 1},
        {0, 2, 6, 0, 4},
        {0, 0, 1, 4, 0}};

    int start = 0;
    dijikstra(graph, start);
    
    return 0;
}