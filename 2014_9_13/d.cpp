#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

class HLDecomposition {
    vector < vector<int> > g;
    vector<int> vertex_id, head, heavy, parent, depth;

    int dfs(int curr, int prev) {
        parent[curr] = prev;
        int sub = 1, max_sub = 0;
        for (int next : g[curr]) {
            if (next == prev) continue;
            depth[next] = depth[curr] + 1;
            int sub_next = dfs(next, curr);
            sub += sub_next;
            if (max_sub < sub_next) {
                max_sub = sub_next;
                heavy[curr] = next;
            }
        }
        return sub;
    }

    void bfs() {
        int k = 0;
        queue<int> q({0});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int i = h; i != -1; i = heavy[i]) {
                vertex_id[i] = k++;
                head[i] = h;
                for (int j : g[i]) {
                    if (j != parent[i] && j != heavy[i]) {
                        q.push(j);
                    }
                }
            }
        }
    }

public:
    HLDecomposition(int n)
            : g(n), vertex_id(n, -1), head(n), heavy(n, -1), parent(n), depth(n) {}

    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build() {
        dfs(0, -1);
        bfs();
    }

    int lca(int u, int v) {
        if (vertex_id[u] > vertex_id[v]) swap(u, v);
        if (head[u] == head[v]) return u;
        return lca(u, parent[head[v]]);
    }

    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N;
    HLDecomposition hl(N);
    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        x--; y--;
        hl.add(x, y);
    }

    hl.build();

    cin >> Q;
    for (int i = 0, u, v; i < Q; i++) {
        cin >> u >> v;
        u--; v--;
        cout << hl.distance(u, v) + 1 << "\n";
    }

    return 0;
}
