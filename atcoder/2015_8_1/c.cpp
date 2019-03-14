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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    Flow fl(n*m+2);
    int a[m][n], b[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> b[i][j];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && b[i][j] == 1) {
                ans++;
                fl.add_edge(m*n, i*n+j, 1);
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < m && y < n && a[x][y] == 1 && b[x][y] == 0) {
                        fl.add_edge(i*n+j, x*n+y, 1);
                    }
                }
            } else if (a[i][j] == 1 && b[i][j] == 0) {
                ans++;
                fl.add_edge(i*n+j, m*n+1, 1);
            }
        }
    }

    cout << ans - fl.max_flow(m*n, m*n+1) << "\n";
    return 0;
}