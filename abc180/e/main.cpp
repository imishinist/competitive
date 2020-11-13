#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

typedef long long ll;

#define eps 1e-14
#define MAX_N 17
#define INF 1e18

ll dist(tuple<int, int, int> p1, tuple<int, int, int> p2) {
    auto [a, b, c] = p1;
    auto [p, q, r] = p2;
    return abs(p - a) + abs(q - b) + max(0, r - c);
}

int n;
int d[MAX_N][MAX_N];
ll dp[1 << MAX_N][MAX_N];

ll solve(int S, int v) {
    if (dp[S][v] >= 0) return dp[S][v];

    if (S == (1 << n) - 1 && v == 0) return dp[S][v] = 0;

    ll res = INF;
    for (int u = 0; u < n; u++) {
        if (!(S >> u & 1)) {
            res = min(res, solve(S | 1 << u, u) + d[v][u]);
        }
    }

    return dp[S][v] = res;
}

int main() {
    cin >> n;

    vector<tuple<int, int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        points.push_back(make_tuple(x, y, z));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = dist(points[i], points[j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, 0));

    return 0;
}
