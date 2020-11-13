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
const int mod = 1000000007;

#define eps 1e-14

ll powmod(ll x, ll y) {
    ll res = 1;
    for (ll i = 0; i < y; i++) {
        res = res * x % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    ll ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
    ans %= mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;

    return 0;
}
