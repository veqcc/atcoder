#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> P;

struct Edge {
    int to, cost;
};

int prim(vector<vector<Edge>> &edge) {
    int ret = 0;
    vector <bool> used(edge.size(), false);
    priority_queue <P, vector<P>, greater<P>> q;
    q.push({0, 0});
    while (!q.empty()) {
        P p = q.top(); q.pop();
        int cur = p.second;
        if (used[cur]) continue;
        used[cur] = true;
        ret += p.first;
        for (Edge &e : edge[cur]) {
            q.push({e.cost, e.to});
        }
    }
    return ret;
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
void AOJ_GRL_2_A() {
    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[s].push_back({t, w});
        edge[t].push_back({s, w});
    }

    cout << prim(edge) << '\n';
}

int main() {
    AOJ_GRL_2_A();
    return 0;
}