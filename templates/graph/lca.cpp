#include <iostream>
#include <vector>

using namespace std;

class Lca {
    int N;
    int logN;
    vector<int> depths;
    vector<vector<int>> edge;

    // dop[i][j]: 2^j th parent node from i th node
    vector<vector<int>> dp;

    void calc_depth(int cur, int par, int depth) {
        depths[cur] = depth;
        dp[cur][0] = par;
        for (int ch : edge[cur]) {
            if (ch == par) continue;
            calc_depth(ch, cur, depth + 1);
        }
    }

    void calc_dp() {
        for (int k = 1; k < logN; k++) {
            for (int i = 0; i < N; i++) {
                if (dp[i][k - 1] == -1) {
                    dp[i][k] = -1;
                } else {
                    dp[i][k] = dp[dp[i][k - 1]][k - 1];
                }
            }
        }
    }

public:
    Lca(const vector<vector<int>> &edge, int root) : edge(edge) {
        N = edge.size();
        logN = (sizeof(int) * 8) - __builtin_clz(N);
        depths.resize(N);
        dp.resize(N);
        for (int i = 0; i < N; i++) dp[i].resize(logN, -1);
        calc_depth(root, -1, 0);
        calc_dp();
    }

    // O(logN)
    int lca(int u, int v) {
        // assume depths[u] <= depths[v]
        if (depths[u] > depths[v]) swap(u, v);

        // equalize depth
        int diff = depths[v] - depths[u];
        for (int k = 0; k < logN; k++) {
            if ((diff >> k) & 1) {
                v = dp[v][k];
            }
        }

        if (u == v) return u;

        for (int k = logN - 1; k >= 0; k--) {
            if (dp[u][k] != dp[v][k]) {
                u = dp[u][k];
                v = dp[v][k];
            }
        }

        return dp[u][0];
    }
};


// verified
//  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja
void AOJ_GRL_5_C() {
    int n, k, c, q, u, v;
    cin >> n;
    vector<bool> is_root(n, true);
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            is_root[c] = false;
            edge[i].push_back(c);
            edge[c].push_back(i);
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++) if (is_root[i]) root = i;
    Lca lca(edge, root);
    cin >> q;
    while (q--) {
        cin >> u >> v;
        cout << lca.lca(u, v) << '\n';
    }
}

int main() {
    AOJ_GRL_5_C();
    return 0;
}