#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

#define eps 1e-14

int main() {
    long long n;
    cin >> n;
    vector<ll> A(n);
    ll sum = 0, num = 0, max = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        num += A[i];
        if (max < num) {
            max = num;
        }
        if (ans < sum + max) ans = sum + max;
        sum += num;
    }
    cout << ans << endl;

    return 0;
}
