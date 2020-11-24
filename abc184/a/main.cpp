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
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    cout << a * d - b * c << endl;
    return 0;
}
