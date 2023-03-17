#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adjList[nodes + 1];
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // display graph list
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int child: adjList[i]) {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}