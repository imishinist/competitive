#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

#define eps 1e-14

int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll ans = 0;
    while ((double) a*x <= 2e18) {
        if (a * x >= y || a * x > x + b) {
            break;
        }
        ans++;
        x *= a;
    }
    ans += (y - x - 1) / b;
    cout << ans << endl;
    return 0;
}
