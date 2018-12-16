#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
typedef pair <int, int> P;

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

    int n, k, l;
    cin >> n >> k >> l;

    UnionFind uf_road(n);
    UnionFind uf_rail(n);

    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        uf_road.unite(p, q);
    }

    for (int i = 0; i < l; i++) {
        int r, s;
        cin >> r >> s;
        r--; s--;
        uf_rail.unite(r, s);
    }

    vector <P> ps;
    for (int i = 0; i < n; i++) {
        ps.push_back(make_pair(uf_road.find(i), uf_rail.find(i)));
    }

    map<P, int> count;
    for (int i = 0; i < n; i++) {
        count[ps[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cout << count[ps[i]] << " ";
    }

    return 0;
}