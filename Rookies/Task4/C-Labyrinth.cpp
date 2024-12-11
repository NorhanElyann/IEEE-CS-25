#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    char dir_map[4] = {'R', 'D', 'L', 'U'};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front(); q.pop();
        int x = current.first, y = current.second;

        if (x == end.first && y == end.second) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0], ny = y + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<char> path;
        pair<int, int> p = end;
        while (p != start) {
            pair<int, int> prev = parent[p.first][p.second];
            for (int i = 0; i < 4; i++) {
                if (prev.first + directions[i][0] == p.first && prev.second + directions[i][1] == p.second) {
                    path.push_back(dir_map[i]);
                    break;
                }
            }
            p = prev;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (char c : path) cout << c;
        cout << '\n';
    }

    return 0;
}
