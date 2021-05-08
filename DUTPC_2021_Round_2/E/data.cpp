#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) : x(xx), y(yy){}
};

struct Rect {
    // (a,b) bot left, (c, d) top right
    int a, b, c, d;

    Point tl, tr, bl, br;
    Rect(){}
    Rect (int aa, int bb, int cc, int dd) : a(aa), b(bb), c(cc), d(dd) {
        bl = Point(a, b);
        tr = Point(c, d);
        tl = Point(a, d);
        br = Point(c, b);
    }
};

int n;
Rect rect[(int)(2e5)+10];

struct Event {
    int rect_id;
    int x;
    int add;
    Event(int rid, int x, int a) : rect_id(rid), x (x), add(a){}

    bool operator<(const Event& e) {
        if (x == e.x) return add > e.add;
        return x < e.x;
    }
};

const int N = (int)(2e5)+10;
int as[N], bs[N], cs[N], ds[N];

using ll = long long;

int bitu[N], bitd[N];
void update(int x, int v, int* bit) {
    for (; x<N; x+=(x&(-x))) bit[x] += v;
}
ll query(int x, int* bit) {
    ll sum=0;
    for (; x>0; x-=(x&(-x))) sum += bit[x];
    return sum;
}
ll query(int l, int r, int* bit) {
    return query(r, bit) - query(l-1, bit);
}

void solve() {
    fill(bitu, bitu+N, 0);
    fill(bitd, bitd+N, 0);

    unordered_map<int, int> re;

    cin >> n;
    vector<int> ys;
    for (int i=0; i<n; i++) {
        cin >> as[i] >> bs[i] >> cs[i] >> ds[i];
        ys.push_back(bs[i]);
        ys.push_back(ds[i]);
    }

    sort(ys.begin(), ys.end());
    int cnt=1;
    for (int y : ys) {
        if (re.find(y) == re.end()) re[y] = cnt++;
    }

    for (int i=0; i<n; i++) {
        rect[i] = Rect(as[i], re[bs[i]], cs[i], re[ds[i]]);
    }

    vector<Event> event;
    for (int i=0; i<n; i++) {
        event.push_back(
            Event(i, rect[i].bl.x, +1)
        );
        event.push_back(
            Event(i, rect[i].br.x, -1)
        );
    }
    sort(event.begin(), event.end());

    ll cuml=0;
    ll ans=0;
    for (Event e : event) {
        if (e.add > 0) {
            ll above = query(N-1, rect[e.rect_id].tl.y, bitd);
            ll below = query(rect[e.rect_id].bl.y, 1, bitu);
            ll inter = cuml - above - below;
            ans += inter;

            update(rect[e.rect_id].tl.y, 1, bitu);
            update(rect[e.rect_id].bl.y, 1, bitd);
        } else {
            update(rect[e.rect_id].tl.y, -1, bitu);
            update(rect[e.rect_id].bl.y, -1, bitd);
        }
        cuml += e.add;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}