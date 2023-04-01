#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int>adj_list[N];
int visited[N];

bool detect_cycle(int node, int parent) {

    visited[node] = 1;

    for(int adj_node: adj_list[node]) {
        if(visited[adj_node] == 0) {
            bool got_cycle = detect_cycle(adj_node, node);
            if(got_cycle) {
                return true;
            }
        }
        else if(visited[adj_node] == 1 and adj_node != parent) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        int u, v;
        cin >> u >> v; // u -> v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool cycle_exists = false;

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i] == 0) {
            bool got_cycle = detect_cycle(i, -1);
            if(got_cycle) {
                cycle_exists = true;
                break;
            }
        }
    }

    if(cycle_exists) {
        cout<<"Cycle Exists"<<endl;
    }
    else {
        cout<<"NO cycle"<<endl;
    }

}