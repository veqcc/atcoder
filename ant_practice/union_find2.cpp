#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=200000;
const int MAX_K=100000;
int par[MAX_N];
int rnk[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;

        if (x < 0 || x >= N || y < 0|| y >= N) {
            ans++;
            continue;
        }

        if (t == 1) {
            if (same(x, y+N) || same(x, y+2*N)) {
                ans++;
            } else {
                unite(x, y);
                unite(x+N, y+N);
                unite(x+2*N, y+2*N);
            }
        } else {
            if (same(x, y) || same(x, y+2*N)) {
                ans++;
            } else {
                unite(x, y+N);
                unite(x+N, y+2*N);
                unite(x+2*N, y);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}