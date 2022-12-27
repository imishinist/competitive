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
#include <list>
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


const long MAX=200001;

vector<int> G[MAX];
list<int> ou;
bool V[MAX];
int N;
int indeg[MAX];

//topological sort
void tsort(){
    priority_queue<int, vector<int>, greater<int>> heap;
    rep(i, N) {
        if (indeg[i] == 0) {
            heap.push(i);
        }
    }

    vector<int> ans;
    ans.reserve(N);
    while(!heap.empty()) {
        int i = heap.top(); heap.pop();
        ans.push_back(i);
        rep(j, G[i].size()) {
            int to = G[i][j];
            // popped
            indeg[to]--;
            if (indeg[to] == 0) {
                heap.push(to);
            }
        }
    }
    if (ans.size() != N) {
        cout << -1 << endl;
    } else {
        rep(i, N) {
            cout << ans[i]+1 << (i == N-1 ? '\n' : ' ');
        }
    }
}

void solve(int N, int M, std::vector<int> A,
           std::vector<int> B) {
    rep(i, N) V[i] = false;

    rep(i, M) {
        int a = A[i]-1;
        int b = B[i]-1;
        indeg[b]++;
        G[a].push_back(b);
    }

    tsort();
}

// Generated by 2.9.0 https://github.com/kyuridenamida/atcoder-tools templates:
// (https://github.com/imishinist/competitive/blob/master/boilerplate/main.cpp)
int main() {
    int M;
    cin >> N >> M;
    std::vector<int> A(M);
    std::vector<int> B(M);
    for (int i = 0; i < M; i++) {
        std::scanf("%d", &A[i]);
        std::scanf("%d", &B[i]);
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}