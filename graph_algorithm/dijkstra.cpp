#include <bits/stdc++.h>
using namespace std;

/*
6 8
1 2 4
1 3 4
2 3 2
3 4 3
3 5 6
3 6 1
4 5 2
6 5 3
output: 0 4 4 7 8 5
*/

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];
int d[N], visited[N];
int nodes, edges;

void dijktra(int src)
{
    for (int i = 1; i <= nodes; i++) {
        d[i] = INF;
    }
    d[src] = 0;

    for (int i = 0; i < nodes; i++) {
        int selected_node = -1;
        
        for (int j = 1; j <= nodes; j++) {
            if (visited[j] == 1) continue;
            if (selected_node == -1 || d[selected_node] > d[j]) {
                selected_node = j;
            }
        }
        visited[selected_node] = 1;

        for (auto adj_entry: adj_list[selected_node]) {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if (d[selected_node] + edge_cost < d[adj_node]) {
                d[adj_node] = d[selected_node] + edge_cost;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijktra(src);

    for (int i = 1; i <= nodes; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}