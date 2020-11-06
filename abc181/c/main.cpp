#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

pair<int, int> calc_vector(pair<int, int> a, pair<int, int> b) {
    return make_pair<int, int>(b.first - a.first, b.second - a.second);
}

bool same_direction(pair<int, int> va, pair<int, int> vb) {
    // va.second / va.first == vb.second / vb.first
    return va.second * vb.first == va.first * vb.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        points[i] = p;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> v1 = calc_vector(points[i], points[j]);
            for (int k = j + 1; k < n; k++) {
                pair<int, int> v2 = calc_vector(points[i], points[k]);
                if (same_direction(v1, v2)) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
    
    return 0;
}
