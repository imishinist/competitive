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
typedef long long ll;

#define eps 1e-14

void solve(long long N, std::vector<long long> A) {
    ll sum = 0;
    ll mn = abs(A[0]);
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            cnt++;
        }
        sum += abs(A[i]);
        mn = min(mn, abs(A[i]));
    }
    if (cnt % 2 != 0) {
        sum -= mn * 2;
    }
    cout << sum << endl;
}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    long long N;
    std::scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
