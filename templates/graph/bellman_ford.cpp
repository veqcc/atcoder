#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> P;
const int INF = 1 << 30;

vector <int> bellman_ford(vector<vector<P>> &edge, int s) {
    int V = edge.size();
    vector <int> dist(V, INF);
    dist[s] = 0;
    for (int i = 1; i < V; i++) {
        for (int from = 0; from < V; from++) {
            if (dist[from] == INF) continue;
            for (P e : edge[from]) {
                int to = e.first;
                dist[to] = min(dist[to], dist[from] + e.second);
            }
        }
    }

    // 負の閉路があるならば空のvectorを返す
    for (int from = 0; from < V; from++) {
        if (dist[from] == INF) continue;
        for (P &e : edge[from]) {
            int to = e.first;
            if (dist[to] > dist[from] + e.second) {
                return vector <int>();
            }
        }
    }

    return dist;
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp
void AOJ_GRL_1_B() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<P>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edge[s].push_back({t, d});
    }

    vector <int> dist = bellman_ford(edge, r);

    if (dist.size() == 0) {
        cout << "NEGATIVE CYCLE" << "\n";
        return;
    }

    for (int d : dist) {
        if (d == INF) {
            cout << "INF\n";
        } else {
            cout << d << "\n";
        }
    }
}

int main() {
    AOJ_GRL_1_B();
    return 0;
}