#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long count = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)a[i] + a[mid] >= l) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int low_idx = left;

            left = i + 1, right = n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)a[i] + a[mid] <= r) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int high_idx = right;

            if (low_idx <= high_idx) {
                count += (high_idx - low_idx + 1);
            }
        }
        cout << count << endl;
    }
    return 0;
}
