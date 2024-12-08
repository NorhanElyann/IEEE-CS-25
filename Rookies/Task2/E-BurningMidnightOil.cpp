#include <iostream>
using namespace std;

int main() {
    long long n;
    int k;
    cin>>n>>k;

    long long left= 1, right = n;
    long long answer= n;

    while(left<=right) {
        long long mid= left+(right-left)/2;
        long long total= 0;
        long long v= mid;

        while(v > 0) {
            total += v;
            v /= k;
        }

        if (total>=n) {
            answer=mid;
            right=mid - 1;
        } else {
            left=mid+1;
        }
    }

    cout<<answer<< endl;
    return 0;
}
