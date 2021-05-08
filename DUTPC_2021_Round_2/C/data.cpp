#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 1e6 + 5;
const ll BASE = 998244353;
int n;
ll a[MAX];

ll power(ll x, ll y) {
  if (!y)
    return 1;
  ll tmp = power(x, y / 2);
  if (y % 2)
    return (tmp * tmp % BASE * x) % BASE;
  return tmp * tmp % BASE;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int beforePower = n - 1;
  ll sum = power(2, n - 1) * a[0] % BASE, prefixSum = 0;
  for (int i = 1; i < n; ++i) {
    ll tmp1 = power(2, beforePower - 1) * a[i - 1] % BASE;
    ll tmp2 = power(2, beforePower - 1) * a[i] % BASE;
    prefixSum = (prefixSum + tmp1) % BASE;
    sum = (sum + prefixSum + tmp2) % BASE;

    --beforePower;
  }

  cout << sum;

  return 0;
}
