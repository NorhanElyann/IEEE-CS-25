#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int left = 0, right = n - 1;
    int alice_time = 0, bob_time = 0;
    int alice_bars = 0, bob_bars = 0;

    while (left <= right) {
        if (alice_time <= bob_time) {
            alice_time += t[left];
            alice_bars++;
            left++;
        } else {
            bob_time += t[right];
            bob_bars++;
            right--;
        }
    }

    cout << alice_bars << " " << bob_bars << endl;

    return 0;
}

