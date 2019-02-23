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
typedef unsigned int uint;
using namespace std;

typedef pair<int, int> P;
vector <int> edge[150005];
vector <int> ans;

void dfs(int cur, int par) {
    ans.push_back(cur);
    for (int child : edge[cur]) {
        if (child == par) continue;
        dfs(child, cur);
    }
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
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    UnionFind uf(150005);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        a = uf.find(a);
        b = uf.find(b);
        uf.unite(a, b);

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int root = uf.find(0);

    dfs(root, -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}