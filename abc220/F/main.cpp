#include <algorithm>
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

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

void solve(long long N, std::vector<long long> u, std::vector<long long> v) {}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> u(N - 1);
    std::vector<long long> v(N - 1);
    for (int i = 0; i < N - 1; i++) {
        std::scanf("%lld", &u[i]);
        std::scanf("%lld", &v[i]);
    }
    solve(N, std::move(u), std::move(v));
    return 0;
}
