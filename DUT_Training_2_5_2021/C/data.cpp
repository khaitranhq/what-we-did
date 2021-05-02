#include <bits/stdc++.h>
using namespace std;

// struct Hasher {
//     size_t operator()(const vector<int>& rhs) const {
//         string id = "";
//         for (int i=0; i<26; i++) {
//             // cerr << p.first << ' ' << p.second << '\n';
//             id += to_string(rhs[i]) + ";";
//         }
//         // cerr << id << '\n';
//         return hash<string>{}(id);
//     }
// };

string a, b;

void solve() {
    set<vector<int>> histogram_set;
    cin >> a >> b;
    swap(a, b);

    int n = a.length();
    for (int i=0; i<n; i++) {
        vector<int> histogram (26, 0);
        for (int j=i; j<n; j++) {
            histogram[a[j]-'a']++;
            histogram_set.insert(histogram);
        }
    }

    int l=0, r=-1;
    for (int i=0; i<n; i++) {
        vector<int> histogram (26, 0);
        for (int j=i; j<n; j++) {
            histogram[b[j]-'a']++;
            if (histogram_set.find(histogram) != histogram_set.end()) {
                if (j-i+1 > r-l+1) {
                    l = i;
                    r = j;
                }
            }
        }
    }
    if (l <= r) {
        cout << b.substr(l, r-l+1) << '\n';
    } else {
        cout << "NONE\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
