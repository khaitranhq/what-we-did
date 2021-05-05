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
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;

const int MAX = 2e3 + 5;
const double EPS = 1e-6;
int n;
iii circles[MAX];

struct DisjoinSet {
  int par[MAX];
  double ans;

  int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }

  void join(int u, int v, double d) {
    if ((u = root(u)) == (v = root(v)))
      return;

    ans += d;
    if (par[v] < par[u])
      swap(u, v);

    par[u] += par[v];
    par[v] = u;
  }

  DisjoinSet() {
    memset(par, -1, sizeof(par));
    ans = 0;
  }
} DSU;

double dist(int i, int j) {
  int xa = circles[i].se.fi, ya = circles[i].se.se, ra = circles[i].fi;
  int xb = circles[j].se.fi, yb = circles[j].se.se, rb = circles[j].fi;

  return sqrt(pow((xa - xb), 2) + pow((ya - yb), 2)) - ra - rb;
}

bool cmp(dii x, dii y){
  return x.fi - y.fi < -EPS;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> circles[i].se.fi >> circles[i].se.se >> circles[i].fi;
  }

  vector<dii> circlePairs;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      circlePairs.push_back({dist(i, j), {i, j}});

  sort(circlePairs.begin(), circlePairs.end(), cmp);

  for (auto circlePair : circlePairs) {
    DSU.join(circlePair.se.fi, circlePair.se.se, circlePair.fi);
  }
  cout << fixed << setprecision(8) << DSU.ans;
  return 0;
}
