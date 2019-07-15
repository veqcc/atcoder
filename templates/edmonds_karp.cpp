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

class EdmondsKarp {
    const int INF = 1 << 30;
    struct Edge {
        int to, cap, rev;
    };

    int n;
    vector <vector<Edge>> G;
    vector<int> distance;

    int bfs(int s, int t) {
        fill(distance.begin(), distance.end(), INF);
        queue<int> q;
        q.push(s);
        distance[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (Edge &e : G[v]) {
                if (distance[e.to] > distance[v] + 1 && e.cap > 0) {
                    q.push(e.to);
                    distance[e.to] = distance[v] + 1;
                }
            }
        }
        return distance[t];
    }

public:
    EdmondsKarp(int n) : n(n), G(n), distance(n) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int) G[to].size()});
        G[to].push_back({from, 0, (int) G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            int d = bfs(s, t);
            if (d == INF) return flow;

            // residual graph において、BFSで探したpathの最小のcapacityを求める
            int f = INF;
            int v = t;
            for (int i = d - 1; i >= 0; i--) {
                for (Edge &e : G[v]) {
                    if (distance[e.to] == i && G[e.to][e.rev].cap > 0) {
                        v = e.to;
                        f = min(f, G[e.to][e.rev].cap);
                        break;
                    }
                }
            }

            // 上記の最小capacityに基づいて residual graph を更新する
            v = t;
            for (int i = d - 1; i >= 0; i--) {
                for (Edge &e : G[v]) {
                    if (distance[e.to] == i && G[e.to][e.rev].cap > 0) {
                        v = e.to;
                        e.cap += f;
                        G[e.to][e.rev].cap -= f;
                        break;
                    }
                }
            }

            flow += f;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    EdmondsKarp ek(V);
    for (int e = 0; e < E; e++) {
        int u, v, c;
        cin >> u >> v >> c;
        ek.add_edge(u, v, c);
    }

    cout << ek.max_flow(0, V - 1) << "\n";
    return 0;
}