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

int main() {
    string s;
    cin >> s;
    cout << s;
    if (s[s.size() - 1] == 's') {
        cout << "es" << endl;
    } else {
        cout << "s" << endl;
    }
    return 0;
}
