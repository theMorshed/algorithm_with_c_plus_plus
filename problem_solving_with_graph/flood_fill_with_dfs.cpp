#include <bits/stdc++.h>
using namespace std;

/*
5 8
########
#..#...#
####.#.#
#..#...#
########

Output -> 3
while there exists an empty cell
    - find an empty unvisited cell
    - run dfs() from that cell

*/

const int N = 2002;
int maze[N][N], visited[N][N];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
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

    if(maze[x][y] == -1) {
        return false;
    }
    return true;
}

void dfs(pair<int, int> src)
{
    visited[src.first][src.second] = 1;
    int x = src.first;
    int y = src.second;

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        pair<int, int> adj_node = {new_x, new_y};

        if (is_inside(adj_node) and is_safe(adj_node) and visited[new_x][new_y] == 0) {
            dfs(adj_node);
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            if (input[j] == '#') {
                maze[i][j] = -1;
            }
        }
    }

    int room_count = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 and maze[i][j] == 0) {
                dfs({i, j});
                room_count++;
            }
        }
    }

    cout << room_count << endl;

    return 0;
}