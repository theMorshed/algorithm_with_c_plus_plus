#include <bits/stdc++.h>
using namespace std;

/*
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/

const int N = 2000;
int maze[N][N], visited[N][N];
int level[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_valid(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 and x < n and y >= 0 and y < m) {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1) {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    
    q.push(src);

    while (!q.empty()) {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_valid(adj_node) and is_safe(adj_node) and visited[new_x][new_y] == 0) {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{    
    cin >> n >> m;
    pair<int, int> src, dst;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            level[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == '#') {
                maze[i][j] = -1;
            }
            else if (line[j] == 'A') {
                src = {i, j};
            }
            else if (line[j] == 'B') {
                dst = {i, j};
            }
        }
    }

    bfs(src);

    if (level[dst.first][dst.second] == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << level[dst.first][dst.second] << endl;
    }

    return 0;
}