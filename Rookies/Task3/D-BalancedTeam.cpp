#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0, right = 0, maxteamsize = 0;

    while (right < n) {
        if (a[right] - a[left] <= 5) {
            maxteamsize= max(maxteamsize, right - left + 1);
            right++;
        } else {
            left++;
        }
    }

    cout<<maxteamsize<<endl;

    return 0;
}
