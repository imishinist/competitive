#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 0x3fffffff;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> H(n);
    vector<int> W(m);

    for (int i = 0; i < n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
        cin >> W[i];

    sort(H.begin(), H.end());
    sort(W.begin(), W.end());

    long long ans = 100000000000;
    for (auto w : W) {
        int idx = lower_bound(H.begin(), H.end(), w) - H.begin();
        long long sum = 0;

        if (idx == 0) {
            sum += H[idx] - w;
            for (int i = 1; i < n - 1; i += 2) {
                sum += H[i+1] - H[i];
            }
        } else if (idx == n) {
            idx--;
            sum += w - H[idx];
            for (int i = 0; i < n - 1; i += 2) {
                sum += H[i+1] - H[i];
            }
        } else {
            if (idx % 2 != 0) {
                idx--;
            }
            for (int i = 0; i < idx; i += 2) {
                sum += H[i+1] - H[i];
            }
            sum += abs(H[idx] - w);
            for (int i = idx+1; i < n - 1; i += 2) {
                sum += H[i+1] - H[i];
            }
        }
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);    
    return 0;
}
