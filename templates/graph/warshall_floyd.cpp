#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> P;
const int INF = 2e9;

bool warshall_floyd(vector<vector<int>> &adj) {
    int V = adj.size();

    // i->j と i->k->j を比較する
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][k] == INF || adj[k][j] == INF) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // 負の閉路がある場合falseを返す
    for (int i = 0; i < V; i++) {
        if (adj[i][i] < 0) {
            return false;
        }
    }

    return true;
}

// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
void AOJ_GRL_1_C() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) adj[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int s, t, d;
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
            if (j) cout << " ";
            int d = adj[i][j];
            if (d == INF) cout << "INF";
            else cout << d;
        }
        cout << "\n";
    }
}

int main() {
    AOJ_GRL_1_C();
    return 0;
}