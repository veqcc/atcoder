#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
typedef pair<ll, ll> P;
ll inf = 1e18;

ll total_cost[100005];
ll yen_cost[100005];
ll snk_cost[100005];
vector<P> yen_edge[100005];
vector<P> snk_edge[100005];

// Dijkstra
void dijkstra(ll *D, vector<P> *G, ll s){
    // max priority queue ordered by first element
    // priority_queue < P > q;

    // min priority queue ordered by first element
    priority_queue < P, vector<P>, greater<P> > q;
    for (int i = 0; i < 100005; i++) D[i] = inf;
    D[s]=0;
    q.push(P(0,s));
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        ll y = p.second; // p.second means current node position
        if (D[y] != p.first) continue;
        for (int i = 0; i < G[y].size(); i++) {
            int node = G[y].at(i).first; // edge y->node
            ll cost = G[y].at(i).second; // cost of y->node
            if (D[node] > D[y] + cost) {
                D[node] = D[y] + cost;
                q.push(P(D[node], node)); // P(total cost, current node)
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, m, s, t, u, v, a, b;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a >> b;
        yen_edge[u].push_back(P(v, a));
        yen_edge[v].push_back(P(u, a));
        snk_edge[u].push_back(P(v, b));
        snk_edge[v].push_back(P(u, b));
    }

    dijkstra(yen_cost, yen_edge, s);
    dijkstra(snk_cost, snk_edge, t);

    total_cost[n] = yen_cost[n] + snk_cost[n];
    for (int i = n-1; i > 0; i--) {
        total_cost[i] = min(total_cost[i+1], yen_cost[i] + snk_cost[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << 1000000000000000 - total_cost[i] << "\n";
    }

    return 0;
}