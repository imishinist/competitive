#include <algorithm>
#include <atcoder/all>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reps(i, ini, n) for (int(i) = (ini); (i) < (n); (i)++)
#define rev(i, n) for (int(i) = n; (i) >= 0; (i)--)
#define revs(i, from, to) for (int(i) = from; (i) >= to; (i)--)
#define eps 1e-14

void solve(std::vector<std::vector<long long>> A) {}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    std::vector<std::vector<long long>> A(4, std::vector<long long>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::scanf("%lld", &A[i][j]);
        }
    }
    solve(std::move(A));
    return 0;
}
