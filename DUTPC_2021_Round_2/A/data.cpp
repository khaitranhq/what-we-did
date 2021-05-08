#include <iostream>
using namespace std;

int n, m;
int M[2000][2000];

using ll = long long;
ll dp[2000][2000];
const ll mod = (ll)(1e9)+7;

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			char c; cin >> c;
			M[i][j] = (c=='#');
		}
	}
	dp[0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!M[i+1][j]) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
			if (!M[i][j+1]) dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
		}
	}
	cout << dp[n-1][m-1] << '\n';
}