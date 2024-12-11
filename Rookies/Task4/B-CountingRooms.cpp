#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin>>n>> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin>>grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == '.';
    };

    auto bfs = [&](int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + directions[i][0];
                int ny = cy + directions[i][1];

                if (is_valid(nx, ny)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };

    int room_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                room_count++;
            }
        }
    }

    cout<<room_count<< endl;
    return 0;
}
