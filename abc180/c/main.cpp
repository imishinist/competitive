#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

int main() {
    long long n;
    cin >> n;

    vector<long long> list;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            list.push_back(i);
            if (n != i * i) {
                list.push_back(n / i);
            }
        }
    }
    sort(list.begin(), list.end());
    for (auto l : list) {
        cout << l << endl;
    }
    return 0;
}
