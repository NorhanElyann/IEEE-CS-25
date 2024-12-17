#include <bits/stdc++.h>
using namespace std;

long long min_difference = LLONG_MAX;

void minimalDifference(vector<int> &weights, int index, long long group1_sum, long long group2_sum) {
    if (index == weights.size()) {
        min_difference = min(min_difference, abs(group1_sum - group2_sum));
        return;
    }

    minimalDifference(weights, index + 1, group1_sum + weights[index], group2_sum);

    minimalDifference(weights, index + 1, group1_sum, group2_sum + weights[index]);
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    minimalDifference(weights, 0, 0, 0);

    cout << min_difference << "\n";
    return 0;
}
