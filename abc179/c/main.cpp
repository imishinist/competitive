#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

typedef long long ll;

#define eps 1e-14

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int tmp = n - i;
        for (int j = 1; j * j <= tmp; j++) {
            if (tmp % j == 0) {
                if (tmp == j * j) {
                    ans++;
                    continue;
                }
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
