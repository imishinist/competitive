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
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        int d = s[i] == 'o' ? 1 : -1;
        x = max(x + d, 0);
    }
    cout << x << endl;

    return 0;
}
