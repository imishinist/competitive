#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pii;
typedef vector<pair<long long, long long>> vpii;

#define eps 1e-14

int main() {
    int n;
    cin >> n;
    vpii zw(n);

    vector<ll> z(n), w(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        z[i] = x + y;
        w[i] = x - y;
    }
    sort(z.begin(), z.end());
    sort(w.begin(), w.end());
    cout << max(z[n - 1] - z[0], w[n - 1] - w[0]) << endl;

    return 0;
}
