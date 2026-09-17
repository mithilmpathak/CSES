#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) {
        cin >> row;
    }

    pair<int, int> start, finish;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
            if (grid[i][j] == 'B') {
                finish = {i, j};
            }
        }
    }

    // U, D, L, R
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    char dir[] = {'U', 'D', 'L', 'R'};

    // parent[x][y] = direction used to reach (x,y)
    vector<vector<char>> parent(n, vector<char>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (visited[nx][ny])
                continue;

            if (grid[nx][ny] == '#')
                continue;

            visited[nx][ny] = true;
            parent[nx][ny] = dir[i];

            q.push({nx, ny});
        }
    }

    if (!visited[finish.first][finish.second]) {
        cout << "NO\n";
        return 0;
    }

    string path;

    int x = finish.first;
    int y = finish.second;

    while (x != start.first || y != start.second) {
        char d = parent[x][y];

        path += d;

        if (d == 'U') {
            x++;
        }
        else if (d == 'D') {
            x--;
        }
        else if (d == 'L') {
            y++;
        }
        else if (d == 'R') {
            y--;
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}