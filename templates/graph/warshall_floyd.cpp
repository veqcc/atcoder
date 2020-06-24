#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

// O(N^3)
// return value: whether the graph does not have negative loop
bool warshall_floyd(vector<vector<ll>> &adj) {
    int n = adj.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (adj[i][i] < 0) return false;
    }
    return true;
}

// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
void AOJ_GRL_1_C() {
    int V, E;
    cin >> V >> E;
    vector<vector<ll>> adj(V, vector<ll>(V, INF));
    for (int i = 0; i < V; i++) adj[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int s, t; ll d;
        cin >> s >> t >> d;
        adj[s][t] = d;
    }
    bool negative_loop = warshall_floyd(adj);
    if (!negative_loop) {
        cout << "NEGATIVE CYCLE" << '\n';
        return;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (j) cout << ' ';
            if (adj[i][j] == INF) cout << "INF";
            else cout << adj[i][j];
        }
        cout << '\n';
    }
}

// not verified
//  https://atcoder.jp/contests/abc073/tasks/abc073_d
#include <algorithm>
void AtCoder_2017_9_9_D() {
    int n, m, R, a, b, c;
    cin >> n >> m >> R;
    vector<int> r(R);
    for (int i = 0; i < R; i++) { cin >> r[i]; r[i]--; }
    sort(r.begin(), r.end());
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) adj[i][i] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        if (c < adj[a][b]) adj[a][b] = adj[b][a] = c;
    }
    warshall_floyd(adj);
    int ans = 0;
    for (int i = 1; i < R; i++) ans += adj[r[i - 1]][r[i]];
    while (next_permutation(r.begin(), r.end())) {
        int tmp = 0;
        for (int i = 1; i < R; i++) tmp += adj[r[i - 1]][r[i]];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    // AOJ_GRL_1_C();
    AtCoder_2017_9_9_D();
    return 0;
}