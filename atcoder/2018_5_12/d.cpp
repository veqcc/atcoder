#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

class UnionFind {
    vector<int> par;
    int n;

public:
    UnionFind(int n) : par(n, -1) {}

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    UnionFind uf(100005);
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (uf.same(p[i], i+1)) ans++;
    }

    cout << ans << "\n";
    return 0;
}