#include <bits/stdc++.h>
using namespace std;


const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited,int &current_volume ) {
    visited[i][j] = true;
    current_volume += grid[i][j];
    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !visited[ni][nj] && grid[ni][nj] > 0) {
            dfs(ni, nj, grid, visited, current_volume);
        }
    }
}


int main()
{
    int n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int max_volume = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]>0 && !visited[i][j])
                {
                    int current_volume = 0;
                    dfs(i, j, grid, visited, current_volume);
                    max_volume=max(max_volume,current_volume);
                }
            }
        }
        cout<<max_volume<< endl;
    }
}
