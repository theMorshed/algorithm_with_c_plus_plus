#include <bits/stdc++.h>
using namespace std;

const int nodes = 1e5;
bool visited[nodes];
vector<int> adj_list[nodes];

/*
    1 ------ 2 ----- 3 -------- 6
             |       |
             |       |
             5 ------4
    num of nodes: 6
    num of edges: 6
    edges: 1 - 2, 2 - 3, 2 - 5, 5 - 4, 3 - 4, 3 - 6
*/

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    q.push(node);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        cout << head << " ";

        for (int adj_node: adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int source = 1;
    cout << "BFS: ";
    bfs(source);

    return 0;
}