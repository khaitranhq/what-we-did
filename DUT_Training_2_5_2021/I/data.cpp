#include <bits/stdc++.h>
using namespace std;
#define task "data"

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define FRSZ(i, a) for (int i = 0; i < a.size(); ++i)
#define FDSZ(i, a) for (int i = a.size() - 1; i >= 0; --i)
#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)       \
    {                        \
        FOR(_, 1, n)         \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define debugvi(x)           \
    {                        \
        FRSZ(_, x)           \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int n;
set<string> check;
string rotU(string dice)
{
    char tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = tmp;
    return dice;
}
string rotL(string dice)
{
    char tmp = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = dice[4];
    dice[4] = tmp;
    return dice;
}
string rot(string dice)
{
    string res = "666666";
    for (int i = 1; i <= 8; i++)
    {
        res = min(res, dice);
        // cerr << dice << endl;
        check.insert(dice);
        for (int j = 1; j <= 4; j++)
        {
            dice = rotL(dice);
            res = min(res, dice);
            // cerr << dice << endl;
            check.insert(dice);
        }
        // dice = rotL(dice);
        if (i == 4)
            dice = rotL(dice);
        dice = rotU(dice);
    }
    // cerr << check.size() << endl;
    return res;
}
int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin >> n;
    string in;
    map<string, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        in = "";
        for (int j = 1; j <= 6; j++)
        {
            int x;
            cin >> x;
            in += x + '0';
        }
        string dice = rot(in);
        cnt[dice]++;
    }
    int ans = 0;
    for (auto i : cnt)
    {
        ans = max(i.se, ans);
    }
    cout << ans << endl;
    return 0;
}
