#include <bits/stdc++.h>
using namespace std;

struct Dir {
	string name;
	vector<Dir*> subdir;
	long long size=0;
	char sign=' ';
};
bool cmp(const Dir* a, const Dir* b) {
	return a->name < b->name;
}

Dir* root = new Dir;

int n;
vector<pair<string, int>> inputs;
int t;
void input() {
	cin >> n;
	inputs.resize(n);
	for (auto &p : inputs) 
		cin >> p.first >> p.second;
	sort(inputs.begin(), inputs.end());
	cin >> t;
}

vector<string> split(string fpath) {
	vector<string> tokens;
	string tmp;
	for (int i=1; i<(int)fpath.length(); i++) {
		if (fpath[i] != '/') tmp += fpath[i];
		else {
			tokens.push_back(tmp);
			tmp = "";
		}
	}
	return tokens;
}

Dir* find(Dir* curr, string name) {
	for (Dir* d : curr->subdir) {
		if (d->name == name) return d;
	}
	return NULL;
}

void recur_tree(Dir* curr, vector<string>& subd, int& size, int d) {
	if (d == subd.size()) {
		curr->size += size;
	} else {
		Dir* nxt = find(curr, subd[d]);
		if (nxt == NULL) {
			Dir* newdir = new Dir;
			newdir->name = subd[d];
			curr->subdir.push_back(newdir);
			nxt = newdir;
		}

		recur_tree(nxt, subd, size, d+1);
		curr->size += size;
	}
}

void update(string fpath, int size) {
	vector<string> subs = split(fpath);
	recur_tree(root, subs, size, 0);
}

int crawl(Dir* curr) {
	if (curr->subdir.empty()) {
		curr->sign = ' ';
		if (curr->size >= t) return 1;
		return 0;
	} 

	sort(curr->subdir.begin(), curr->subdir.end(), cmp);
	int expand=0;
	for (Dir* d : curr->subdir) 
		expand |= crawl(d);
	if (expand) curr->sign = '-';
	else curr->sign = '+';

	if (curr->size >= t) return 1;
	return 0;
}

void print(Dir* curr, string prefix="") {
	prefix += curr->name + "/";
	cout << curr->sign << ' ' << prefix << ' ' << curr->size << '\n';
	if (curr->sign == '-') {
		for (Dir* nxt : curr->subdir) {
			print(nxt, prefix);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	root->name = "";
	input();

	for (auto &p : inputs) update(p.first, p.second);

	crawl(root);
	print(root);
}
