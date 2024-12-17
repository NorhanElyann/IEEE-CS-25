#include <bits/stdc++.h>
using namespace std;

void generatePermutations(string &s, int index, set<string> &uniquePerms) {
    if (index == s.size()) {
        uniquePerms.insert(s);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        generatePermutations(s, index + 1, uniquePerms);
        swap(s[index], s[i]);
    }
}

int main() {
    string s;
    cin >> s;

    set<string> uniquePerms;
    generatePermutations(s, 0, uniquePerms);

    cout << uniquePerms.size() << "\n";
    for (const auto &perm : uniquePerms) {
        cout << perm << "\n";
    }

    return 0;
}

