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
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    // A  ~m~  P ~n~ B
    // *-------+-----*
    // nXa + mXb / (m + n)
    double px = (double)(gy * sx + sy * gx) / (double)(abs(gx - sx));
    printf("%lf\n", px);

    return 0;
}
