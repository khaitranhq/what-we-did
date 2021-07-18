#include <bits/stdc++.h>
using namespace std;

int R, n;
string grid[55];

void input() {
	cin >> R >> n;
	for (int i=1; i<=R+3; i++) {
		cin >> grid[i];
	}
}

int countEmptySeat(int rowIdx) {
	return count(grid[rowIdx].begin(), grid[rowIdx].end(), '-');
}

int chooseRow() {
	vector<int> rows;
	// Empty seat in a row right after exit row
	// 1+1, r/2+2 + 1
	if (grid[2].find('-') != string::npos)
		rows.push_back(2);
	if (grid[R/2+3].find('-') != string::npos)
		rows.push_back(R/2+3);
	
	if (rows.empty()) {
		for (int r=1; r<R+3; r++) {
			if (r == 1) continue;
			if (r == R/2+2) continue;
			rows.push_back(r);
		}
	}
	
	// select rows with the largest number of empty seats
	vector<int> rows2;
	int maxEmpty=-1;
	for (int& r : rows) 
		maxEmpty = max(maxEmpty, countEmptySeat(r));
	for (int& r : rows) 
		if (countEmptySeat(r) == maxEmpty) rows2.push_back(r);

	// closest to exit
	vector<int> rows3;
	int clst=INT_MAX;
	for (int r : rows2) 
		for (int er : {1, R/2+2, R+3}) 
			clst = min(clst, abs(r - er));
	for (int r : rows2) 
		for (int er : {1, R/2+2, R+3}) 
			if (clst == abs(r - er)) {
				rows3.push_back(r);
				break;
			}

	return rows3[0];	
}

const vector<vector<int>> priority {
	{4, 6},	{2, 8}, {0, 10}, {5}, {1, 9}
};
int chooseCol(int row) {
	vector<int> cols;
	for (const vector<int>& prior : priority) {
		int found=0;
		for (const int &c : prior) 
			if (grid[row][c] == '-') {
				cols.push_back(c);
				found=1;
			}
		if (found) break;
	}
	if (cols.size() == 2) {
		int l=0, r=0;
		for (int i=1; i<=R+3; i++) {
			for (int j=0; j<11; j++) {
				int nonEmpty = !(grid[i][j] == '-' || grid[i][j] == '.');
				if (j < 5) l+=nonEmpty;
				if (j > 5) r+=nonEmpty;
			}
		}
		if (l <= r) {
			for (int c : cols) 
				if (c < 5) return c;
		} else {
			for (int c : cols) 
				if (c > 5) return c;
		}
	} else {
		return cols[0];
	}
}

int main() {
	input();
	char pass='a';
	while (n--) {
		int r = chooseRow();
		int c = chooseCol(r);
		grid[r][c] = pass;
		pass++;
	}
	for (int i=1; i<=R+3; i++) {
		cout << grid[i] << '\n';
	}
}
