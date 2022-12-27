#include <algorithm>
#include <atcoder/all>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reps(i, ini, n) for (int(i) = (ini); (i) < (n); (i)++)
#define rev(i, n) for (int(i) = n; (i) >= 0; (i)--)
#define revs(i, from, to) for (int(i) = from; (i) >= to; (i)--)
#define eps 1e-14


string slice(string s, int l, int r) {
    string tmp = "";
    for (int i = l; i < r; i++) {
        tmp += s[i];
    }
    return tmp;
}

void solve(std::string S) {
    string ss = S + S;

    string max_string = S;
    string min_string = S;
    rep(i, S.size()+1) {
        string tmp = slice(ss, i, i + S.size());
        if (max_string < tmp) {
            max_string = tmp;
        }
        if (tmp < min_string) {
            min_string = tmp;
        }
    }

    cout << min_string << endl;
    cout << max_string << endl;
}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
