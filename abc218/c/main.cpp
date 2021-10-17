#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

vector<vi> rotate(vector<vi> s) {
    int n = s.size();
    vector<vi> ret = vector<vi>(n);
    for (int i = 0; i < n; i++) {
        ret[i] = vi(n);
        for (int j = 0; j < n; j++) {
            ret[i][j] = s[n-j-1][i];
        }
    }
    return ret;
}

vector<vi> upleft(vector<vi> s) {
    int minx = s.size() + 1, miny = s.size() + 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (s[i][j] == 1) {
                minx = min(minx, j);
                miny = min(miny, i);
            }
        }
    }

    vector<vi> ret = vector<vi>(s.size());
    for (int i = 0; i < s.size(); i++) {
        ret[i] = vi(s.size());
        for (int j = 0; j < s.size(); j++) {
            if (i+miny >= s.size() || j+minx >= s.size()) {
                ret[i][j] = 0;
            } else {
                ret[i][j] = s[i+miny][j+minx];
            }
        }
    }
    return ret;
}

bool same(vector<vi> s, vector<vi> t) {
    if (s.size() != t.size()) return false;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void print(vector<vi> s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            printf("%d ", s[i][j]);
        }
        puts("");
    }
    puts("");
}

bool solve() {
    int n;
    cin >> n;

    vector<vi> S = vector<vi>(n);
    vector<vi> T = vector<vi>(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        S[i] = vi(n);
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                S[i][j] = 1;
            } else {
                S[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        T[i] = vi(n);
        for (int j = 0; j < n; j++) {
            if (t[j] == '#') {
                T[i][j] = 1;
            } else {
                T[i][j] = 0;
            }
        }
    }
    auto ss = upleft(S);

    for (int k = 0; k < 4; k++) {
        auto rotated = rotate(T);
        T = rotated;
        auto tt = upleft(rotated);
        if (same(ss, tt)) {
            return true;
        }
    }
    return false;
}

int main() {
    if (solve()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}