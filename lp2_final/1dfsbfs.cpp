#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

void dfs(const vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            dfs(graph, neighbour, visited);
        }
    }
}

void bfs(const vector<vector<int>> &graph, queue<int> &queue, vector<bool> &visited)
{
    if (queue.empty())
        return;

    int node = queue.front();
    queue.pop();
    cout << node << " ";

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            visited[neighbour] = true;
            queue.push(neighbour);
        }
    }

    bfs(graph, queue, visited);
}

int main()
{
    int n, e;
    cout << "\nEnter the Number of Vertices: ";
    cin >> n;
    cout << "\nEnter The Number of Edges: ";
    cin >> e;

    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter The start ,end vetrex of edge and weight(u v w):";
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "\nEnter The Start Vertex: ";
    cin >> start;
    cout << endl;

    cout << "\nDFS : ";
    dfs(graph, start, visited);
    cout << endl;
    
    cout << "\nBFS : ";
    queue<int> q;
    q.push(start);
    vector<bool> visit(n, false);
    visit[start] = true;
    bfs(graph, q, visit);

    return 0;
}