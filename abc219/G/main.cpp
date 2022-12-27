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

void solve(long long N, long long M, long long Q, std::vector<long long> u,
           std::vector<long long> v, std::vector<long long> x) {}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    long long N;
    std::scanf("%lld", &N);
    long long M;
    std::scanf("%lld", &M);
    long long Q;
    std::scanf("%lld", &Q);
    std::vector<long long> u(M);
    std::vector<long long> v(M);
    for (int i = 0; i < M; i++) {
        std::scanf("%lld", &u[i]);
        std::scanf("%lld", &v[i]);
    }
    std::vector<long long> x(Q);
    for (int i = 0; i < Q; i++) {
        std::scanf("%lld", &x[i]);
    }
    solve(N, M, Q, std::move(u), std::move(v), std::move(x));
    return 0;
}