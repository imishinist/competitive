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

typedef long long ll;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reps(i, ini, n) for (int(i) = (ini); (i) < (n); (i)++)
#define rev(i, n) for (int(i) = n; (i) >= 0; (i)--)
#define revs(i, from, to) for (int(i) = from; (i) >= to; (i)--)
#define eps 1e-14

void solve(long long N, long long K, std::vector<std::vector<long long>> A) {
    atcoder::mcf_graph<>
}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    long long N;
    std::scanf("%lld", &N);
    long long K;
    std::scanf("%lld", &K);
    std::vector<std::vector<long long>> A(N, std::vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::scanf("%lld", &A[i][j]);
        }
    }
    solve(N, K, std::move(A));
    return 0;
}