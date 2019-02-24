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

struct TopologicalSort {
    int n;
    vector <set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort() {}

    TopologicalSort(int sz) : n(sz), G(n), used(n), indeg(n), p(0) {}

    void add_edge(int s, int t) {
        G[s].insert(t);
    }

    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u:G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }

    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);
        for (int i = 0; i < n; i++) for (int v:G[i]) indeg[v]++;
        for (int i = 0; i < n; i++) if (indeg[i] == 0 && !used[i]) bfs(i);
        return p;
    }
};

vector <int> edge[2005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    UnionFind uf(n + m);
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '=') {
                uf.unite(i, n + j);
            }
        }
    }

    map<int, int> mp;
    int sz = 0;
    for (int i = 0; i < n + m; i++) {
        if (uf.find(i) == i) mp[i] = sz++;
    }

    bool flag = true;
    TopologicalSort ts(sz);
    for (int i = 0; i < n; i++) {
        int p = mp[uf.find(i)];
        for (int j = 0; j < m; j++) {
            int q = mp[uf.find(n + j)];
            if (s[i][j] == '>') {
                if (p == q) flag = false;
                edge[q].push_back(p);
                ts.add_edge(q, p);
            } else if (s[i][j] == '<') {
                if (p == q) flag = false;
                edge[p].push_back(q);
                ts.add_edge(p, q);
            }
        }
    }

    vector<int> sorted_vertex = ts.build();
    if (!flag || sorted_vertex.size() != sz) {
        cout << "No\n";
        return 0;
    }

    int dp[sz];
    fill(dp, dp + sz, 1);
    for (int vertex : sorted_vertex) {
        for (int child : edge[vertex]) {
            dp[child] = max(dp[child], dp[vertex] + 1);
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << dp[mp[uf.find(i)]] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << dp[mp[uf.find(n + i)]] << " ";
    }
    cout << "\n";
    return 0;
}