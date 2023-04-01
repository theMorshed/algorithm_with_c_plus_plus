#include <bits/stdc++.h>
using namespace std;

const int nodes = 2e5 + 5;
bool visited[nodes];
int color[nodes];
vector<int> adj_list[nodes];

bool bfs(int src)
{
    visited[src] = true;
    color[src] = 1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int head = q.front();
        q.pop();
        
        for (int node: adj_list[head]) {
            if (!visited[node]) {
                if (color[head] == 1) color[node] = 2;
                else color[node] = 1;
                
                visited[node] = true;
                q.push(node);
            }
            else {
                if (color[head] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    bool bicolorable;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bicolorable = bfs(i);
            if (!bicolorable) {
                break;
            }
        }    
    }
    
    if (bicolorable) {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}