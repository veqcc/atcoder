#include <functional>
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

int main() {
    int l, r;
    cin >> l >> r;

    UnionFind uf(r - l + 1);
    for (int i = l; i <= r; i++) {
        for (int j = 2; i * j <= r; j++) {
            uf.unite(i - l, i * j - l);
        }
    }

    int ans = -1;
    for (int i = l; i <= r; i++) {
        if (uf.find(i - l) == i - l) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}