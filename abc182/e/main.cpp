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

#define MAX_H 1500
#define MAX_W 1500

int board[MAX_H][MAX_W];
bool lights[MAX_H][MAX_W];
bool blocks[MAX_H][MAX_W];

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lights[--a][--b] = true;
    }
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        blocks[--c][--d] = true;
    }

    for (int y = 0; y < h; y++) {
        bool illuminatedRight = false;
        bool illuminatedLeft = false;
        // 横方向
        for (int x = 0; x < w; x++) {
            int lx = w - x - 1, ly = h - y - 1;
            if (lights[y][x]) {
                illuminatedRight = true;
            }
            if (blocks[y][x]) {
                illuminatedRight = false;
            }
            if (lights[ly][lx]) {
                illuminatedLeft = true;
            }
            if (blocks[ly][lx]) {
                illuminatedLeft = false;
            }

            if (illuminatedRight) {
                board[y][x] += 1;
            }
            if (illuminatedLeft) {
                board[ly][lx] += 1;
            }
        }
    }
    for (int x = 0; x < w; x++) {
        bool illuminatedUp = false;
        bool illuminatedDown = false;
        // 縦方向
        for (int y = 0; y < h; y++) {
            int lx = w - x - 1, ly = h - y - 1;
            if (lights[y][x]) {
                illuminatedDown = true;
            }
            if (blocks[y][x]) {
                illuminatedDown = false;
            }
            if (lights[ly][lx]) {
                illuminatedUp = true;
            }
            if (blocks[ly][lx]) {
                illuminatedUp = false;
            }

            if (illuminatedDown) {
                board[y][x] += 1;
            }
            if (illuminatedUp) {
                board[ly][lx] += 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!blocks[i][j] && board[i][j] > 0) {
                cnt += 1;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
