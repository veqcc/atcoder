#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

typedef pair<int ,int> P;
int N, M;
int inf = 1000000007;
int cost[300];
vector<P> edge[300];

void dijkstra(int *D, vector<P> *G, int goal){
    priority_queue < P, vector<P>, greater<P> > q;
    for (int i = 0; i < N; i++) D[i] = inf;
    D[0]=0;
    q.push(P(0,0));
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int y = p.second;
        if (D[y] != p.first) continue;
        for (int i = 0; i < G[y].size(); i++) {
            int node = G[y].at(i).first;
            if (y == 0 && node == goal) continue;
            int cost = G[y].at(i).second;
            if (D[node] > D[y] + cost) {
                D[node] = D[y] + cost;
                q.push(P(D[node], node));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        edge[u].push_back(P(v, l));
        edge[v].push_back(P(u, l));
    }

    int ans = inf;
    for (int i = 0; i < edge[0].size(); i++) {
        dijkstra(cost, edge, edge[0][i].first);
        ans = min(ans, cost[edge[0][i].first] + edge[0][i].second);
    }

    if (ans == inf) ans = -1;
    cout << ans << "\n";
    return 0;
}