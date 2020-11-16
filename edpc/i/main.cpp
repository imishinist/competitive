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

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;
    // i枚目まで使った時の、表がj枚の確率
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            // i-1枚目まででj枚表の確率 * 裏の確率
            // i-1枚目まででj-1枚表の確率 * 表の確率
            if (j != 0) dp[i][j] = dp[i-1][j] * (1-p[i-1]) + dp[i-1][j-1] * p[i-1];
            else dp[i][j] = dp[i-1][j] * (1-p[i-1]);
        }
    }

    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[n][i];
    }
    printf("%.10lf\n", ans);

    return 0;
}
