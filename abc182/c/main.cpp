#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

bool is_3mul(string n) {
    int sum = 0;
    for (int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
    }
    return sum % 3 == 0;
}

int main() {
    string n;
    cin >> n;

    int ans = 20;
    for (int i = 0; i < (1 << n.size()) - 1; i++) {
        int cnt = n.size();
        string cp_n = "";
        for (int j = 0; j < n.size(); j++) {
            if (!((i >> j) & 1)) {
                cnt--;
                cp_n = cp_n + n[j];
            }
        }
        if (is_3mul(cp_n)) {
            ans = min(ans, cnt);
        }
    }
    cout << ((ans != 20) ? ans : -1) << endl;

    return 0;
}
