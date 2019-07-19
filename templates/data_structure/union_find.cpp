#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> par;
    int n;

public:
    UnionFind(int sz) : par(sz, -1) {}

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -par[find(x)];
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
void AOJ_DSL_1_A() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << uf.same(x, y) << '\n';
        } else {
            uf.unite(x, y);
        }
    }
}

int main() {
    AOJ_DSL_1_A();
    return 0;
}