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

string s[50];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m, b=0, w=0;
    cin >> n >> m;

    Flow fl(n*m+2);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'b') {
                b++;
                fl.add_edge(n*m, i*m+j, 100);
            } else if (s[i][j] == 'w') {
                w++;
                fl.add_edge(i*m+j, n*m+1, 100);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'b') {
                for (int k = 0; k < 4; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == 'w') {
                        fl.add_edge(i*m+j, x*m+y, 100);
                    }
                }
            }
        }
    }

    int flow = fl.max_flow(n*m, n*m+1);
    b -= flow / 100;
    w -= flow / 100;
    int ten = min(b, w);
    b -= ten;
    w -= ten;

    cout << flow + ten * 10 + b + w << "\n";
    return 0;
}