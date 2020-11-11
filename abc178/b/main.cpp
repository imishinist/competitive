#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
using ll = long long;

#define eps 1e-14

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
    return 0;
}
