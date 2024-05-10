#include <bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(int color[])
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i < N; i++)
        cout <<i<< ":" << color[i] << "\n";

    cout << "\n";
}
bool isSafe(int v, bool graph[N][N], int color[], int c)
{
    for (int i = 0; i < N; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
bool graphColoringUtil(bool graph[N][N], int m, int color[],int v)
{
    if (v == N)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[N][N], int m)
{
    int color[N];
    for (int i = 0; i < N; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    printSolution(color);
    return true;
}
int main()
{
    bool graph[N][N] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
    };
    
    int m = 3;
    graphColoring(graph, m);
    return 0;
}
