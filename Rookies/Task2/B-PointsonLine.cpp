#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin>>n>>d;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin>>x[i];
    }

    long long result = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && x[j] - x[i] <= d) {
            j++;
        }
        long long count = j - i - 1;
        if (count >= 2) {
            result += count*(count - 1) / 2;
        }
    }

    cout<<result<< endl;
    return 0;
}
