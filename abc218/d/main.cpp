#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

#define eps 1e-14

int main() {
    int n;
    cin >> n;

    vpii points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (points[i].first < points[j].first && points[i].second < points[j].second) {
                if (binary_search(points.begin(), points.end(), make_pair(points[i].first, points[j].second))
                    && binary_search(points.begin(), points.end(), make_pair(points[j].first, points[i].second))) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}
