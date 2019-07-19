#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Kruskal法
//   証明: http://drken1215.hatenablog.com/entry/20121223/1356230697

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
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -par[find(x)]; }
};

struct Edge {
    int from, to, cost;
};

int kruskal(vector<Edge> &edge, int V) {
    sort(edge.begin(), edge.end(), [](const Edge &a, const Edge &b) {
        return a.cost < b.cost;
    });

    UnionFind uf(V);
    int ret = 0;
    for (Edge &e : edge) {
        if (uf.unite(e.from, e.to)) {
            ret += e.cost;
        }
    }
    return ret;
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
void AOJ_GRL_2_A() {
    int V, E;
    cin >> V >> E;

    vector <Edge> edge;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge.push_back({s, t, w});
    }

    cout << kruskal(edge, V) << "\n";
}

int main() {
    AOJ_GRL_2_A();
    return 0;
}