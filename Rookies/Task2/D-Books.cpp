#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxbooks = 0, currenttime = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        currenttime += a[right];
        while (currenttime > t) {
            currenttime -= a[left];
            left++;
        }
        maxbooks= max(maxbooks, right - left + 1);
    }
    cout<<maxbooks<<endl;
    return 0;
}
