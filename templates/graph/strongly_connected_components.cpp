#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 強連結成分分解
//   計算量: O(V + E)
//   operator[]: 頂点kが属する強連結成分の番号を返す

class StronglyConnectedComponents {
    int V;
    vector<vector<int>> G, rG;
    vector <int> comp; // 強連結成分の番号（トポロジカル順）
    vector <int> order; // DFSで辿った順
    vector <int> used;

    void dfs(int cur) {
        if (used[cur]) return;
        used[cur] = true;
        for (int to : G[cur]) dfs(to);
        order.push_back(cur);
    }

    void rdfs(int cur, int cnt) {
        if (comp[cur] != -1) return;
        comp[cur] = cnt;
        for (int to : rG[cur]) rdfs(to, cnt);
    }

public:
    StronglyConnectedComponents(vector<vector<int>> &edge) {
        V = edge.size();
        G.resize(V);
        rG.resize(V);
        comp.assign(V, -1);
        used.assign(V, false);
        for (int i = 0; i < V; i++) {
            for (int e : edge[i]) {
                G[i].push_back(e);
                rG[e].push_back(i);
            }
        }
    }

    int operator[](int k) { return comp[k]; }

    void build(vector<vector<int>> &buff) {
        for (int i = 0; i < V; i++) dfs(i);
        reverse(order.begin(), order.end());
        int cnt = 0;
        for (int i : order) if (comp[i] == -1) rdfs(i, cnt++);
        buff.resize(cnt);
        for (int i = 0; i < V; i++) {
            for (int to : G[i]) {
                int x = comp[i], y = comp[to];
                if (x == y) continue;
                buff[x].push_back(y);
            }
        }
    }
};


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
void AOJ_GRL_3_C() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edge(V), buff;
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
    }

    StronglyConnectedComponents scc(edge);
    scc.build(buff);

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << (scc[u] == scc[v] ? 1 : 0) << "\n";
    }
}

int main() {
    AOJ_GRL_3_C();
    return 0;
}