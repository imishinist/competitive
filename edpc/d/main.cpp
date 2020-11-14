#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            auto wi = items[i].first, vi = items[i].second;
            if (j < wi) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-wi]+vi);
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
