#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int M[2000][2000];

#define fi first
#define se second
queue<pair<int, int>> Q[11];
int cnt[11];
int s[11];

int main() {
	cin >> n >> m >> p;
	for (int i=1; i<=p; i++) cin >> s[i];
	
	for (int i=0; i<=n+1; i++) fill(M[i], M[i]+m+2, -1);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			M[i][j] = 0;
			char c; cin >> c;
			if (c == '.') continue;
			
			int player = (int)(c - '0');
            M[i][j] = player;
            cnt[player]++;
			Q[player].push({i, j});
		}
	}

	// for (int i=0; i<=n+5; i++) {
		// for (int j=0; j<=m+5; j++) {
            // cerr << M[i][j] << ' ';
        // }
        // cerr << endl;
    // }
	
	while (true) {
		int flag = true;
		for (int i=1; i<=p; i++) {
			if (!Q[i].empty()) {
				flag = false;

				queue<tuple<int, int, int>> qcurr;
                // cerr << i << "={";
				while (!Q[i].empty()) {
					int x, y;
					x = Q[i].front().first;
                    y = Q[i].front().second;
                    // cerr << "(" << x << "," << y << "), ";

                    Q[i].pop();
					qcurr.push({0, x, y});
				}
                // cerr << "}";
				
				while (!qcurr.empty()) {
					int dd, x, y;
					tie(dd, x, y) = qcurr.front(); qcurr.pop();
                    
					
					if (dd < s[i]) {
                        for (int d=-1; d<=1; d+=2) {
                            int nx = x+d;
                            if (M[nx][y] == 0) {
                                M[nx][y] = i;
                                cnt[i]++;
                                qcurr.push({dd+1, nx, y});
                            }
                        }
                        for (int d=-1; d<=1; d+=2) {
                            int ny = y+d;
                            if (M[x][ny] == 0) {
                                M[x][ny] = i;
                                cnt[i]++;
                                qcurr.push({dd+1, x, ny});
                            }
                        }
					} else {
                        // cerr << x << ' ' << y << '|' << i << endl;
						Q[i].push({x, y});
					}
				}
			}
		}
		if (flag) break;
	}

	for (int i=1; i<=p; i++) {
		cout << cnt[i] << ' ';
	}
	cout << endl;
}