#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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

vector <int> edges[200005];
int ans[200005];
bool use_root = false;

int dfs(int cur, int par, int root) {
    if (cur == root && use_root) return -1;

    vector <int> permutation = {cur};
    for (int i : edges[cur]) {
        if (i == par) continue;
        int ret = dfs(i, cur, root);
        if (ret >= 0) permutation.push_back(ret);
    }

    if (permutation.size() == 1) return cur;

    if (par == root) {
        permutation.push_back(root);
        use_root = true;
    }

    int sz = permutation.size();
    for (int i = 0; i < sz; i++) {
        int j = (i + 1) % sz;
        ans[permutation[i]] = permutation[j];
    }

    return -1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (!uf.same(u, v)) {
            edges[u].push_back(v);
            edges[v].push_back(u);
            uf.unite(u, v);
        }
    }

    for (int i = 0; i < n; i++) {
        if (edges[i].size() == 1) {
            dfs(i, -1, i);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}