#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int INF = 1 << 30;

struct Edge {
    int to; int cap; int rev;
    Edge(int t, int c, int r) : to(t), cap(c), rev(r) {}
};

struct Flow {
    vector <vector<Edge>> G;
    vector<bool> used;
    Flow(int n) : G(n), used(n, false) {}
    void add_edge(int from, int to, int cap) {
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, 0, G[from].size() - 1));
    }
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int W, N, M, Q, X;
    cin >> W;

    cin >> N;
    int J[N];
    for (int i = 0; i < N; i++) cin >> J[i];

    cin >> M;
    int C[M];
    for (int i = 0; i < M; i++) cin >> C[i];

    bool table[N][M];
    fill(table[0], table[N], true);
    for (int i = 0; i < M; i++) {
        cin >> Q;
        for (int j = 0; j < Q; j++) {
            cin >> X;
            X--;
            table[X][i] = false;
        }
    }

    Flow fl(N+M+2);
    for (int i = 0; i < N; i++) fl.add_edge(N+M, i, J[i]);
    for (int i = 0; i < M; i++) fl.add_edge(N+i, N+M+1, C[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (table[i][j]) {
                fl.add_edge(i, N+j, J[i]);
            }
        }
    }

    if (fl.max_flow(N+M, N+M+1) >= W) {
        cout << "SHIROBAKO\n";
    } else {
        cout << "BANSAKUTSUKITA\n";
    }

    return 0;
}