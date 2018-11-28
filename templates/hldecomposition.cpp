#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Heavy-Light Decomposition
class HLDecomposition {
    vector < vector<int> > g;
    vector<int> vertex_id, head, heavy, parent, depth;

    // create heavy edges
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

    // create head
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

    // lowest Common Ancestor
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
    HLDecomposition hl(2);
    hl.add(0, 1);
    hl.build();
    hl.distance(0, 1);
    return 0;
}