#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int par[110];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    par[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

// Startの直線とGoalの直線が同じ連結成分になったら通過できる
// 小さい辺から順に接続させて同じ連結成分になれば,その時の
// 辺の長さの半分が、最高の円の半径になる
// 同じ連結成分になったらそれより大きい円は通過させられないため

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    const int S = n, T = n + 1;
    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < n; i++) {
        auto [x, y] = points[i];
        edges.emplace_back(y + 100, i, S);
        edges.emplace_back(100 - y, i, T);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];
            edges.emplace_back(hypot(x1 - x2, y1 - y2), i, j);
        }
    }

    sort(edges.begin(), edges.end());

    init(n + 2);
    for (auto [length, i, j] : edges) {
        unite(i, j);
        if (same(S, T)) {
            printf("%.5lf\n", length / 2);
            return 0;
        }
    }
    return 0;
}
