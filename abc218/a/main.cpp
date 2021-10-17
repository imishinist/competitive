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
    // type here.
    int n;
    string str;
    cin >> n;
    cin >> str;
    cout << (str.c_str()[n-1] != 'x' ? "Yes" : "No") << endl;
    return 0;
}
