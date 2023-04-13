#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int d[N];
int parent[N];

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

    bool negative_cycle = false;
    int last_updated_node = -1;

    for (int i = 1; i <= nodes; i++) {
        for (int node = 1; node <= nodes; node++) {
            for (pair<int, int> adj_node: adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;

                    if (i == nodes) {
                        negative_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }   
    }
    
    if (negative_cycle) {
        cout << "YES" << endl;

        int selected_node = last_updated_node;
        for (int i = 1; i <= n; i++) {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;
        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true) {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == first_node) {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        for (int node: cycle) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}