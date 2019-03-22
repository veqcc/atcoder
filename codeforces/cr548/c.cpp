#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

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

    ll n, k;
    cin >> n >> k;

    UnionFind uf(n);
    vector <int> sz(n, 1);
    for (int i = 1; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 1) continue;
        u--; v--;
        int sz1 = sz[uf.find(u)];
        int sz2 = sz[uf.find(v)];
        if (uf.unite(u, v)) sz[uf.find(u)] = sz1 + sz2;
    }

    ll ans = pow_mod(n, k, MOD);
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) {
            ans = (ans + MOD - pow_mod(sz[i], k, MOD)) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}