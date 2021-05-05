#include <bits/stdc++.h>
using namespace std;
#define task "data"

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define FRSZ(i, a) for (int i = 0; i < a.size(); ++i)
#define FDSZ(i, a) for (int i = a.size() - 1; i >= 0; --i)
#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)       \
    {                        \
        FOR(_, 1, n)         \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define debugvi(x)           \
    {                        \
        FRSZ(_, x)           \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
// edge L-tromino
// index L-tromino  1 4
//                  2 3
ll getArea(ll x, ll y, ll n)
{
    if (y >= n + n / 2)
        return 1;
    if (x >= n + n / 2)
        return 3;
    if (x >= n / 2 && y >= n / 2)
        return 4;
    if (y >= n)
        return 1;
    if (x >= n)
        return 3;
    return 2;
}
ll res(ll x, ll y, ll orient, ll n)
{
    if (n == 1)
    {
        return 0;
    }
    ll Area = getArea(x, y, n);
    switch (Area)
    {
    case 1:
        return (res(2 * n - y - 1, x, 1, n / 2) + 1) % 4;
        break;
    case 2:
        return res(x, y, 0, n / 2);
        break;
    case 3:
        return (res(y, n * 2 - x - 1, 3, n / 2) + 3) % 4; // -1 + 4
        break;
    case 4:
        return res(x - n / 2, y - n / 2, 0, n / 2);
        break;
    }
    return 0;
}
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll n = 1;
    while (x >= n && y >= n)
    {
        n *= 2;
    }
    while (x >= 2 * n || y >= 2 * n)
    {
        n *= 2;
    }
    cout << res(x, y, 0, n) << endl;
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
