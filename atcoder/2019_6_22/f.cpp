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

vector <int> xc[100005], yc[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    UnionFind uf(n);
    vector <int> x(n), y(n);
    vector <P> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        X[i] = P(x[i], i);
        Y[i] = P(y[i], i);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 0; i < n - 1; i++) {
        if (X[i].first == X[i+1].first) {
            uf.unite(X[i].second, X[i+1].second);
        }

        if (Y[i].first == Y[i+1].first) {
            uf.unite(Y[i].second, Y[i+1].second);
        }
    }

    for (int i = 0; i < n; i++) {
        int par = uf.find(i);
        xc[par].push_back(x[i]);
        yc[par].push_back(y[i]);
    }

    ll ans = -n;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) != i) continue;

        sort(xc[i].begin(), xc[i].end());
        xc[i].erase(unique(xc[i].begin(), xc[i].end()), xc[i].end());

        sort(yc[i].begin(), yc[i].end());
        yc[i].erase(unique(yc[i].begin(), yc[i].end()), yc[i].end());

        ans += xc[i].size() * yc[i].size();
    }

    cout << ans << "\n";
    return 0;
}