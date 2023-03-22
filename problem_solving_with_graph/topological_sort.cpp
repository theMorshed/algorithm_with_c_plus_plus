// problem link - https://cses.fi/problemset/task/1679/
// Assumption: Graph is acyclic
/*
5 3
4 5
3 1
1 2

4 5 3 1 2
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int> adj_list[N];
int visited[N];

stack<int> node_st;

void dfs(int node)
{
    visited[node] = 1;

    for (int adj_node: adj_list[node]) {
        if (!visited[adj_node]) {
            dfs(adj_node);
        }
    }

    node_st.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while(!node_st.empty()) {
        cout << node_st.top() << " ";
        node_st.pop();
    }
    cout << endl;

    return 0;
}