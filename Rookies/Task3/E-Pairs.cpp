#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_set<int> elements;
    int count = 0;

    for (int num : arr) {
        if (elements.find(num - k) != elements.end()) {
            count++;
        }
        if (elements.find(num + k) != elements.end()) {
            count++;
        }
        elements.insert(num);
    }
    
    cout << count << endl;
    
    return 0;
}
