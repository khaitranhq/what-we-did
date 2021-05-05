#include <bits/stdc++.h>
using namespace std;

int n, k;

#define EPS 1e-9
// 1, a > b
// 0, a == b
// -1, a < b
int compare(double a, double b) {
    // if (a == b) return 0;
    // if (a > b) return 1;
    // return -1;
    if (abs(a-b) < EPS) return 0;
    if (a > b + EPS) return 1;
    return -1;
}

struct Point {
    int id;

    int x, y;
    double ang;
    double sqrdist, dist;
    Point(int a, int b, int i) : x(a), y(b) {
        ang = atan2(y, x);
        id = i;
        sqrdist = x*x + y*y;
        dist = sqrt(sqrdist);
    }

    int operator<(const Point& p) {
        return compare(ang, p.ang) >= 1; // clockwise
    }

    void print() {
        cerr << "-- ID = " << id << '\n';
        cerr << "X=" << x << "|Y=" << y << '\n';
        cerr << "ang=" << ang << '\n';
    }
};
vector<Point> P;

tuple<double, double> calc(Point& p, double r) {
    double pointAng = p.ang;
    double pointCircleAng = acos(
        (p.sqrdist)
            /
        (2*r*p.dist)
    );
    double lowswing = pointAng - pointCircleAng;
    double highswing = pointAng + pointCircleAng;
    // fprintf(stderr, "Low=%.6f High=%.6f\n", lowswing, highswing);
    return make_tuple(highswing, lowswing);
}


int check(double r) {
    vector<pair<double, int>> angSweep;
    for (Point& p : P) {
        if (compare(p.dist, r*2) > 0);
        else {
            double h, l;
            tie(h, l) = calc(p, r);

            angSweep.push_back({h, 1});
            angSweep.push_back({l, -1});

            angSweep.push_back({h-M_PI*2, 1});
            angSweep.push_back({l-M_PI*2, -1});
        }
    }

    sort(angSweep.begin(), angSweep.end(),
        [&](pair<double, int> a, pair<double, int> b) -> int {
            if (compare(a.first, b.first) == 0) {
                return a.second < b.second;
            }
            return (compare(a.first, b.first) > 0);
        }
    );
    // sort(angSweep.begin(), angSweep.end());
    // reverse(angSweep.begin(), angSweep.end());

    // cerr << "r = " << r << ' ';
    int cuml = 0;
    for (auto& pr : angSweep) {
        if (pr.first < -M_PI*3) break;
        // cerr << (pr.first) << ' ' << (pr.second) << endl;

        cuml += pr.second;
        if (cuml >= k) {
            // cerr << "Y\n";
            return true;
        }
    }
    // cerr << "N\n";
    return false;
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        // cin >> px[i] >> py[i];
        int x, y; cin >> x >> y;
        P.push_back(Point(x, y, i));
    }

    sort(P.begin(), P.end());
    // for (auto p : P) {
    //     p.print();
    // }

    double ans = -999.0;
    double L = 0.0, R = 2000000; // max radi = sqrt(1000*1000*2) < 2000
    for (int times = 0; times < 100; times++) {
        double mid = (L + R)/2;
        if (check(mid)) {
            ans = mid;
            R = mid;
        } else {
            L = mid;
        }
    }

    if (ans < 0) {
        cout << -1 << endl;
    } else {
        cout << setprecision(9) << fixed << ans << endl;
    }
}

/*
    https://csacademy.com/app/geometry_widget/
    Sample test
    3 2
    1 0
    0 1
    3 3
    Geometry
    0 0 O
    0 1 A
    1 0 B
    3 3 C
    Circle 0.5000000266062394 0.49999999999999994 0.7071068

    Custom test
    3 3
    -1 1
    -1 -1
    -2 0

    Geometry
    0 0 O
    -1 -1 A
    -1 1 B
    -2 0 C
    Circle -1 0 1
    Circle 0 -1 1

    Custom test 2
    4 1
    -1 1
    -1 -1
    -2 0
    1 0

    Geometry
    0 0 O
    -1 -1 A
    -1 1 B
    -2 0 C
    1 0 D
    Circle 0.5 0.0 0.5

    Edge test 1
    2 2
    1000 1
    -1000 1

    Edge test 2
    2 2
    1 1000
    1 -1000

    Edge test 3
    2 2
    1 1000
    -1 1000

    Edge test 4
    2 2
    -1000 1
    1000 0
*/
