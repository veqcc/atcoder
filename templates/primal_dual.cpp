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

class PrimalDual {
    const int INF = 1 << 30;

    struct Edge {
        int to, cap, cost, rev;
    };

    int n;
    vector<vector<Edge>> G;
    vector<int> potential; // ポテンシャル
    vector<int> dist; // 最短距離
    vector<int> prevv, preve; // 直前の頂点と辺

    void dijkstra(int s) {
        fill(dist.begin(), dist.end(), INF);
        priority_queue<P, vector<P>, greater<P>> q;
        dist[s] = 0;
        q.push(P(0, s));
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                Edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] + potential[e.to] > dist[v] + e.cost + potential[v]) {
                    dist[e.to] = dist[v] + e.cost + potential[v] - potential[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push(P(dist[e.to], e.to));
                }
            }
        }
    }

public:
    PrimalDual(int n) : n(n), G(n), potential(n), dist(n), prevv(n), preve(n) {}

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back({to, cap, cost, (int)G[to].size()});
        G[to].push_back({from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int flow) {
        fill(potential.begin(), potential.end(), 0);
        int ret = 0;
        while (flow) {
            dijkstra(s);
            if (dist[t] == INF) return -1;
            for (int v = 0; v < n; v++) potential[v] += dist[v];
            int f = flow;
            for (int v = t; v != s; v = prevv[v]) f = min(f, G[prevv[v]][preve[v]].cap);
            flow -= f;
            ret += f * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = G[prevv[v]][preve[v]];
                e.cap -= f;
                G[v][e.rev].cap += f;
            }
        }
        return ret;
    }
};

int main() {
    int V, E, F;
    cin >> V >> E >> F;

    PrimalDual pd(V);
    for (int e = 0; e < E; e++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        pd.add_edge(u, v, c, d);
    }

    cout << pd.min_cost_flow(0, V - 1, F) << "\n";
    return 0;
}