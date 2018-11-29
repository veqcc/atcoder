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
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    UnionFind uf(2*n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b+n);
        uf.unite(a+n, b);
    }

    // if 二部グラフ
    if (uf.find(0) == uf.find(n)) {
        cout << (n*(n-1)/2)-m;
        return 0;
    }

    ll c = 1;
    for (int i = 1; i < n; i++) {
        if (uf.find(0) == uf.find(i)) c++;
    }
    cout << c*(n-c)-m;
    return 0;
}