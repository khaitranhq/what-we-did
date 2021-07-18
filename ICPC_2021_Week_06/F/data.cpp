#include <bits/stdc++.h>
using namespace std;

long long n;
long long p, r;

long long binExp(long long base, long long exp, long long mod) {
	long long res=1;
	while (exp) {
		if (exp&1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

long long inv(long long x) {
	return binExp(x, p-2, p);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> r;
	if (n >= p*2) {
		if (!r) {
			cout << n << ' ' << n-1 << '\n'; // Correct
		} else {
			cout << "-1 -1\n";
		}
	} else
	if (n >= p) {
		if (r == 0) {
			if (n == 2) {
				cout << "-1 -1\n"; // correct
			} else {
				if (n > p) cout << n << ' ' << n-1 << '\n'; // correct
				else cout << p-1 << ' ' << p-2 << '\n'; // correct
			}
			return 0;
		} else { // correct
			long long fact=1;
			for (int i=2; i<=n; i++) {
				if (i==p) continue;
				fact = fact * i % p;
			}
			for (int ip=1; ip<p; ip++) {
				if (fact * ip % p == r) {
					cout << p << ' ' << ip << '\n';
					return 0;
				}
			}
		}
		cout << "-1 -1\n";
	} else { 
		if (r==0) {
			cout << "-1 -1\n";
			return 0;
		}

		long long fact=1;
		for (int i=2; i<=n; i++) {
			fact = fact * i % p;
		}
		long long ifact = inv(fact);

		for (int i=2; i<=n; i++) {
			long long x = r * i % p * ifact % p;
			if (1 <= x && x < i) {
				cout << i << ' ' << x << '\n';
				return 0;
			}
		}
		cout << "-1 -1\n";
	}
}
