#include <bits/stdc++.h>
using namespace std;
long double a, h;
long double ans;
void solve()
{
    cin >> a >> h;
    ans = 0.0;
    long double prev = 0;
    long double step = 1e-4;
    for (long double i = 1; i - h <= 1e-8; i += step)
    {
        ans += (log(i) * log(i) + prev) * step / 2;
        prev = log(i) * log(i);
    }
    ans /= log(a) * log(a);
    cout << setprecision(15) << ans << endl;
}
int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
