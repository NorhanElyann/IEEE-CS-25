#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node]=true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> p(n+1);
    adj.resize(n+1);
    visited.resize(n+1, false);

    for(int i= 1;i<=n;i++) {
        cin>>p[i];
        if(p[i]!=i) { 
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
    }

    int treecount=0;

    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            treecount++;
            dfs(i);
        }
    }

    cout<<treecount<<endl;

    return 0;
}
