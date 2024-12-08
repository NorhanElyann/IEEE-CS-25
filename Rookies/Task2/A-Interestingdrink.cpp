#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    int a1[n];
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    sort(a1, a1 + n);
    cin >> q;
    while (q--) {
        int qn;
        cin >> qn;
        int count = upper_bound(a1, a1 + n, qn) - a1;
        cout<<count<<endl;
    }
    return 0;
}

