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

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; i++) {
        int P, A, B;
        cin >> P >> A >> B;

        if (P == 0) {
            uf.unite(A, B);
        } else {
            bool ans = uf.same(A, B);
            if (ans) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }

    return 0;
}