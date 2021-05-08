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

const int MAX = 1e5 + 5;
int n, A, B;
int a[MAX];

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n >> A >> B;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (mp.count(A - a[i]) && mp[A - a[i]] == -1) {
      mp[a[i]] = 0;
      mp[A - a[i]] = 0;
    } else if (mp.count(B - a[i]) && mp[B - a[i]] == -1) {
      mp[a[i]] = 1;
      mp[B - a[i]] = 1;
    } else
      mp[a[i]] = -1;
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i)
    if (mp[a[i]] != -1)
      ans.push_back(mp[a[i]]);
    else {
      cout << -1;
      return 0;
    }

  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";

  return 0;
}
