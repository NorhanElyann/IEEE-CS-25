#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, untreated = 0, officers = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            officers += arr[i];
        } else { 
            if (officers > 0) {
                officers--; 
            } else {
                untreated++; 
            }
        }
    }

    cout << untreated << endl;
    return 0;
}
