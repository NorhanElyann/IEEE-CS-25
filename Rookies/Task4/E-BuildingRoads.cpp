#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i]=true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component.push_back(node);

                for (int j = 0; j < graph[node].size(); j++) {
                    int neighbor = graph[node][j];
                    if (!visited[neighbor]) {
                        visited[neighbor]= true;
                        q.push(neighbor);
                    }
                }
            }

            components.push_back(component);
        }
    }

    int num_new_roads= components.size() - 1;
    cout << num_new_roads << endl;

    for (int i=1; i<components.size(); i++) {
        cout<<components[i - 1][0]<<" "<<components[i][0]<< endl;
    }

    return 0;
}
