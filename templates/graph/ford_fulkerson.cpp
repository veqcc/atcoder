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

class FordFulkerson {
    const int INF = 1 << 30;
    struct Edge {
        int to, cap, rev;
    };

    int n;
    vector<vector<Edge>> G;
    vector<bool> used;

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;

        for (Edge &e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
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
    FordFulkerson(int n) : n(n), G(n), used(n) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    FordFulkerson ff(V);
    for (int e = 0; e < E; e++) {
        int u, v, c;
        cin >> u >> v >> c;
        ff.add_edge(u, v, c);
    }

    cout << ff.max_flow(0, V - 1) << "\n";
    return 0;
}