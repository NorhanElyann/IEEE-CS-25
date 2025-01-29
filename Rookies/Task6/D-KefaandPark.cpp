#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> cats;
int n,m,result = 0;

void dfs(int node, int parent, int concequtivecats) {
    if (cats[node]) {
        concequtivecats++;
    } else {
        concequtivecats= 0;
    }

    if (concequtivecats>m) return;

    bool isleaf=true;

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            isleaf= false;
            dfs(neighbor,node,concequtivecats);
        }
    }

    if (isleaf) {
        result++;
    }
}

int main() {
    cin>>n>>m;
    cats.resize(n);
    adj.resize(n);

    for(int i= 0;i<n;i++) {
        cin>>cats[i];
    }

    for(int i= 0;i<n-1;i++) {
        int x,y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0,-1,0);

    cout<<result<<endl;

    return 0;
}
