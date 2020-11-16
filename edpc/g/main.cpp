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
#define MAX_N 100000

int n, m;
vector<vector<int>> edges;
vector<int> dp;

int dfs(int node) {
    if (edges[node].size() == 0) {
        return dp[node] = 0;
    }
    if (dp[node] != 0) {
        return dp[node];
    }

    int ans = 0;
    for (int i = 0; i < edges[node].size(); i++) {
        ans = max(ans, dfs(edges[node][i]) + 1);
    }
    return dp[node] = ans;
}

int main() {
    cin >> n >> m;
    
    dp.resize(n+1);
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[--x].push_back(--y);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    
    return 0;
}
