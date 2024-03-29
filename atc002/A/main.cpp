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
#include <iomanip>
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

using P = pair<int, int>;

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    int R, C;
    cin >> R >> C;

    P s, g;
    // y x
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;


    vector<string> field(R);

    rep(i, R) cin >> field[i];

    queue<pair<P, int>> q;
    q.push(make_pair(s, 0));
    int ans = 0;
    vector<vector<int>> memo = vector<vector<int>>(R, vector<int>(C));
    while(q.size()) {
        auto [point, cnt] = q.front(); q.pop();
        auto [y, x] = point;
        if (point == g) {
            ans = cnt;
            break;
        }
        if (memo[y][x] != 0) {
            continue;
        }
        memo[y][x] = cnt;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        rep(k, 4) {
            int nx = dx[k] + x, ny = dy[k] + y;
            if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if (field[ny][nx] == '#') continue;

            q.push(make_pair(P(ny, nx), cnt+1));
        }
    }
    cout << ans << endl;


    return 0;
}
