#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
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

    int n, m, k, l;
    cin >> n >> m;
    vector <int> lan[100005];
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> l;
            lan[l].push_back(i);
        }
    }

    UnionFind uf(100005);

    for (int i = 1; i <= m; i++) {
        if (lan[i].size() < 2) continue;
        for (int j = 1; j < lan[i].size(); j++) {
            uf.unite(lan[i][j-1], lan[i][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        if (!(uf.same(i, i-1))) {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    return 0;
}