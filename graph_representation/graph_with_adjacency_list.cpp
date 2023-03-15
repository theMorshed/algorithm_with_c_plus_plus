#include <bits/stdc++.h>
using namespace std;

int main()
{
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        // for a directed graph with an edge pointing from u
        // to v,we just assign adjMat[u][v] as 1
    }

    // display graph matrix
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}