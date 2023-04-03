/*
1 ------ 2 ----- 3 -------- 6
        |       |
        |       |
        5 ------4
6 6
1 2
2 3
2 5
5 4
3 4
3 6
output: 1 2 3 5 4 6
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
bool visited[N];
int graph[N][N];
int nodes, edges;

void bfs(int src)
{
    visited[src] = true;
    queue<int> q;
    q.push(src);
    
    while (!q.empty()) {
        int head = q.front();
        q.pop();
        cout << head << " ";
        
        for (int i = 1; i <= nodes; i++) {
            if (graph[head][i] == 1) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
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
    
    bfs(1);
    
    return 0;
}