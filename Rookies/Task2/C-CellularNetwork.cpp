#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cities(n), towers(m);

    for (int i = 0; i < n; ++i) cin >> cities[i];
    for (int i = 0; i < m; ++i) cin >> towers[i];

    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());

    int l = 0, r = 2e9, result = r;

    for (; l <= r;) {
        int mid = l + (r - l) / 2;
        bool feasible = true;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (j < m && towers[j] < cities[i] - mid) {
                ++j;
            }
            if (j == m || abs(towers[j] - cities[i]) > mid) {
                feasible = false;
                break;
            }
        }

        if (feasible) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
