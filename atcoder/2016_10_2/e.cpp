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

string s[100];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> s[i];

    Flow fl(2*h*w + 2);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                if (s[i][j] == 'X') {
                    cout << -1 << '\n';
                    return 0;
                }

                fl.add_edge(i*2*w+2*j, 2*h*w+1, 1);
                continue;
            }

            if (s[i][j] == 'X') {
                fl.add_edge(2*h*w, i*2*w+2*j+1, INF);
            } else {
                fl.add_edge(i*2*w+2*j, i*2*w+2*j+1, 1);
            }

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (s[x][y] == '.') {
                    fl.add_edge(i*2*w+2*j+1, x*2*w+2*y, INF);
                }
            }
        }
    }

    cout << fl.max_flow(2*h*w, 2*h*w+1) << "\n";
    return 0;
}