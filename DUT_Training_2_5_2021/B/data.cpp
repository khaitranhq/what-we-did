#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-4

// x == y return 0
// x < y return -1
// x > y return 1
int compare(double x, double y) {
    if ( abs(x - y) <= EPS ) return 0;
    if ( y > x + EPS ) return -1;
    return 1;
}

int n;

string pitch[] = {
    "A", "A#", "B", "C", "C#",
    "D", "D#", "E", "F", "F#",
    "G", "G#", "A"
};

map<double, string> key;

string pitch_name[5] {
    "G major",
    "C major",
    "Eb major",
    "F# minor",
    "G minor"
};
set<string> allowed[5] {
    {"G", "A", "B", "C", "D", "E", "F#"},
    {"C", "D", "E","F","G","A","B"},
    {"Eb","F","G","G","Ab","Bb","C","D"},
    {"F#","G#","A","B","C#","D","E"},
    {"G","A","Bb","C","D","Eb","F"}
};

string conv(string pi) {
    static unordered_map<string, string> __ {
        {"A#", "Bb"}, {"Bb", "A#"},
        {"C#", "Db"}, {"Db", "C#"},
        {"D#", "Eb"}, {"Eb", "D#"},
        {"F#", "Gb"}, {"Gb", "F#"},
        {"G#", "Ab"}, {"Ab", "G#"}
    };
    if (__.find(pi) == __.end()) return pi;
    return __[pi];
}

void solve() {
    cin >> n;

    vector<string> _keys;
    for (int i=0; i<n; i++) {
        double d; cin >> d;
        
        while (compare(d, 440) == -1) d *= 2;
        while (compare(d, 880) != -1) d /= 2;
        for (auto p : key) {
            if (compare(d, p.first) == 0) {
                _keys.push_back(p.second);
                //cerr << "@" << d << " " << p.second << "\n";
                break;
            }
        }
        //cerr << "@" << d << "--\n";
    }

    int ans=-1;
    for (int i=0; i<5; i++) {
        int ok=1;
        for (string key : _keys) {
            string key2 = conv(key);
            if (allowed[i].find(key) == allowed[i].end() && allowed[i].find(key2) == allowed[i].end()) ok = 0;
        }
        if (ok) {
            if (ans==-1) ans=i;
            else ans += 10;
        }
    }

    //cerr << "@ans=" << ans << endl;
    if (ans == -1 || ans >= 5) cout << "cannot determine key\n";
    else {
        cout << pitch_name[ans] << "\n";
        for (string p : _keys) {
            if (allowed[ans].find(p) != allowed[ans].end()) cout << p << '\n';
            else cout << conv(p) << '\n';
        }
    }
}

int main() {
    for (int i=0; i<12; i++) {
        double freq = 440 * pow(2, i*1.0/12);
        key[freq] = pitch[i];
    }

    // for (int i=0; i<12; i++) p2i[pitch[i]] = i;
    // p2i["Bb"] = p2i["A#"];
    // p2i["Db"] = p2i["C#"];
    // p2i["Eb"] = p2i["D#"];
    // p2i["Gb"] = p2i["F#"];
    // p2i["Ab"] = p2i["G#"];


    // cerr << setprecision(9) << fixed << showpoint;
    // for (auto p : key) cerr <<p.first << ' ' << p.second << endl;
    
    solve();
}
