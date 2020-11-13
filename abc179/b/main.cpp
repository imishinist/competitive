#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

int main() {
    int n;
    cin >> n;
    vpii d(n);

    bool ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int d1, d2;
        cin >> d1 >> d2;

        if (d1 == d2) {
            cnt++;
        } else {
            cnt = 0;
        }

        ans |= (cnt >= 3);
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
