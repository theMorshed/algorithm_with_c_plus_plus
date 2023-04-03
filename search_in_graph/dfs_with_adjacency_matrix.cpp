/*
1 ------ 4 ----- 3 -------- 5
        |       |
        |       |
        6 ------2
6 6
1 4
4 3
4 6
6 2
3 2
3 5
output: 1 4 3 2 6 5
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
bool visited[N];
int graph[N][N];
int nodes, edges;

void dfs(int src)
{
    visited[src] = true;
    cout << src << " ";
          
    for (int i = 1; i <= nodes; i++) {
        if (graph[src][i] == 1) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    
    for (int i = 0; i <= nodes; i++) {
        for (int j = 0; j <= nodes; j++) {
            graph[i][j] = 0;
        }
    }
    
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    dfs(1);
    
    return 0;
}