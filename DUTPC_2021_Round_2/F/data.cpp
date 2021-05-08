#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    string a, b;
    long long c;
    int n;
    cin >> n;
    map<string, long long> cnt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        cnt[a] += c;
        cnt[b] += c;
    }
    for (auto i : cnt)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}
