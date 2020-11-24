#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

#define eps 1e-14

const int inf = 1e9 + 7;
#define MAX_V 1000
#define MAX_N 100

int main() {
    int N, W;
    cin >> N >> W;
    vector<ll> w(N + 1);
    vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    // 価値がj以下となるようなi個目まで選んだ時の重さの最小値
    vector<vector<ll>> dp(N + 1, vector<ll>(MAX_V * MAX_N + 1));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= MAX_V * MAX_N; j++) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= MAX_V * MAX_N; j++) {
            if (j - v[i] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    ll ans = MAX_V * MAX_N;
    while (dp[N][ans] > W) ans--;
    cout << ans << endl;
    return 0;
}
