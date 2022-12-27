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

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    long long H;
    std::scanf("%lld", &H);
    long long W;
    std::scanf("%lld", &W);
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> r(N);
    std::vector<long long> c(N);
    std::vector<long long> a(N);

    vector<pair<int, int>> rc(N);

    vector<vector<int>> field = vector<vector<int>>(H, vector<int>(W));
    for (int i = 0; i < N; i++) {
        std::scanf("%lld", &r[i]);
        std::scanf("%lld", &c[i]);
        std::scanf("%lld", &a[i]);
        r[i]--;
        c[i]--;
        field[r[i]][c[i]] = a[i];
        rc[i] = make_pair(r[i], c[i]);
    }

    map<int, int> indeg;
    map<int, vector<int>> G;

    for (int i = 0; i < N; i++) {
        int rr = rc[i].first, cc = rc[i].second;
        int from = rr * W + cc;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int rrr = rc[j].first, ccc = rc[j].second;
            if (rr != rrr && cc != ccc) continue;
            int to = rrr * W + ccc;

            if (a[i] < a[j]) {
                indeg[from]++;
                G[to].push_back(from);
            }
        }
    }


    map<int, int> ans;
    function<void(int, int)> dfs = [&](int v, int depth) {
        ans[v] = max(ans[v], depth);
        for (auto to : G[v]) {
            dfs(to, depth + 1);
        }
    };


    for (auto m : G) {
        // 自分に向かっている辺がないやつ(start)
        if (indeg[m.first] == 0) {
            dfs(m.first, 0);
        }
    }

    for (int i = 0; i < N; i++) {
        int v = rc[i].first * W + rc[i].second;
        cout << ans[v] << endl;
    }

    return 0;
}
