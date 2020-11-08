#define MAX_N 100

int par[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    par[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}
