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

// verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp

class Dinic {
    const int INF = 1 << 30;
    struct Edge {
        int to, cap, rev;
    };

    int n;
    vector<vector<Edge>> G;
    vector<int> level; // sからの距離
    vector<int> iter; // どこまで調べ終わったか

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue <int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (Edge &e : G[v]) {
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (level[e.to] > level[v] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int n) : n(n), G(n), level(n), iter(n) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            int f = dfs(s, t, INF);
            while (f > 0) {
                flow += f;
                f = dfs(s, t, INF);
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Dinic dinic(V);
    for (int e = 0; e < E; e++) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }

    cout << dinic.max_flow(0, V - 1) << "\n";
    return 0;
}