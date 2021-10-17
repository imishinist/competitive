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
    for (int i = 0; i < 26; i++) {
        int n;
        cin >> n;
        printf("%c", n+'a'-1);
    }
    puts("");
    return 0;
}
