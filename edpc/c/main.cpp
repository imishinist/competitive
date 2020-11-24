#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

int main() {
    int n;
    cin >> n;

    vector<vector<int>> costs(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    vector<vector<int>> dp(n, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = costs[0][i];
    }

    for (int i = 1; i < n; i++) {
        // j: i-1日に何を選んでいたか
        for (int j = 0; j < 3; j++) {
            // k: i日に何を選ぶか
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + costs[i][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;

    return 0;
}
