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

    long long m = 0;
    long long e = 0;
    long long c = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        m += abs(x);
        e += abs(x) * (long long)abs(x);
        c = max(c, abs(x));
    }

    printf("%lld\n%.15lf\n%lld\n", m, sqrt(e), c);
    return 0;
}
