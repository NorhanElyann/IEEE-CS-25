#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int start = 0, end = 0, totaltime = 0, maxbooks = 0;
    
    while (end < n) {
        totaltime += a[end];
        
        while (totaltime > t) {
            totaltime -= a[start];
            start++;
        }
        
        maxbooks = max(maxbooks, end - start + 1);
        end++;
    }
    
    cout << maxbooks << endl;
    
    return 0;
}
