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

    vector<int> sum1((n + 1) / 2);
    vector<int> sum2((n + 1) / 2);

    for (int i = 0; i + 1 < n; i += 2) {
        int j = i + 1;
        sum1[i / 2 + 1] = sum1[i / 2] + H[i+1] - H[i];
        sum2[j / 2 + 1] = sum2[j / 2] + H[j+1] - H[j];
    }

    long long ans = 100000000000;
    for (auto w : W) {
        int idx = lower_bound(H.begin(), H.end(), w) - H.begin();
        long long sum = 0;
        if (idx % 2 != 0) {
            idx--;
        }
        sum += abs(H[idx] - w);
        sum += sum1[idx / 2] + sum2[n / 2] - sum2[idx / 2];
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);    
    return 0;
}
