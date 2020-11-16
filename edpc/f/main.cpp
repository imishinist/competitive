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
    string s, t;
    cin >> s;
    cin >> t;

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    int len = dp[s.size()][t.size()];
    int i = s.size();
    int j = t.size();
    string ans(len, ' ');
    while(len > 0) {
        if (s[i-1] == t[j-1]) {
            ans[len-1] = s[i-1];
            i--;
            j--;
            len--;
        } else if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
