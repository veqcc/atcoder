#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
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
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    UnionFind uf(n);

    vector <ll> ans(m);
    vector <ll> sz(n, 1);

    ll sm = (ll)n * (ll)(n-1) / 2;
    for (int i = m-1; i >= 0; i--) {
        ans[i] = sm;
        int pa = uf.find(a[i]);
        int pb = uf.find(b[i]);
        if (pa == pb) continue;

        sm -= sz[pa] * sz[pb];
        int sum = sz[pa] + sz[pb];
        uf.unite(pa, pb);
        sz[uf.find(pa)] = sum;
    }

    for (ll ret : ans) {
        cout << ret << "\n";
    }

    return 0;
}