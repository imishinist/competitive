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

    vi A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> table(1000);
    for (int i = 2; i <= 1000; i++) {
        for (int a : A) {
            if (a % i == 0) {
                table[i]++;
            }
        }
    }

    auto it = max_element(table.begin(), table.end());
    cout << it - table.begin() << endl;
    return 0;
}
