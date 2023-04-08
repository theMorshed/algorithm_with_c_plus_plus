#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int d[N], parent[N];

vector<pair<int, int>> adj_list[N];

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    for (int i = 1; i <= nodes; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src = 1;
    int dest_node = 4;
    d[src] = 0;
    parent[src] = -1;
    bool negative_cycle = false;

    for (int i = 1; i <= nodes; i++) {
        for (int node = 1; node <= nodes; node++) {
            for (pair<int, int> adj_node: adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                parent[v] = u;
                
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    
                    if (i == nodes) {
                        negative_cycle = true;
                    }
                }
            }
        }   
    }
    
    if (!negative_cycle) {
        for (int i = 1; i <= nodes; i++) {
            cout << d[i] << " ";
        }
        cout << endl;
    
        vector<int> path;
        int selected_node = dest_node;
    
        while(true) {
            path.push_back(selected_node);
            if (selected_node == src) {
                break;
            }
            selected_node = parent[selected_node];
        }
    
        reverse(path.begin(), path.end());
    
        for (int node: path) {
            cout << node << " ";
        }
        cout << "\n";
    } else {
        cout << "Negative Cycle Found" << endl;
    }

    return 0;
}