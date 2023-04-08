#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
int d[N];

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
    d[src] = 0;

    for (int i = 1; i < nodes; i++) {
        for (int node = 1; node < nodes; node++) {
            for (pair<int, int> adj_node: adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                }
            }
        }   
    }
    
    for (int i = 1; i <= nodes; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}