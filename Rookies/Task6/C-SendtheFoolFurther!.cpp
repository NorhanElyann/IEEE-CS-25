#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;
int maxcost=0;

void dfs(int node,int currentcost) {
    visited[node] = true;
    maxcost = max(maxcost,currentcost);

    for (auto neighbor : adj[node]) {
        int nextnode= neighbor.first;
        int edgecost= neighbor.second;
        if (!visited[nextnode]) {
            dfs(nextnode, currentcost + edgecost);
        }
    }
}

int main() {
    int n;
    cin>>n;

    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n - 1; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(0,0);

    cout<<maxcost<<endl;

    return 0;
}



