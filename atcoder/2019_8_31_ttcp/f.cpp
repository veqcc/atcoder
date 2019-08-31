#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
typedef pair <ll, int> P;
const ll INF = 1LL << 60;

vector<ll> dijkstra(vector<vector<P>> &edge, int s) {
    vector <ll> dist(edge.size(), INF);
    priority_queue <P, vector<P>, greater<P>> q;
    q.push({0, s});
    dist[s] = 0;
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int cur = p.second;
        ll cost = p.first;
        if (dist[cur] < cost) continue;
        for (P nxt : edge[cur]) {
            int next_node = nxt.second;
            ll cost_sum = cost + nxt.first;
            if (dist[next_node] > cost_sum) {
                dist[next_node] = cost_sum;
                q.push({cost_sum, next_node});
            }
        }
    }
    return dist;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, w, x, y, z;
    cin >> n >> m >> w >> x >> y >> z;
    w--; x--; y--; z--;

    vector<vector<P>> edge(n + 2), rev_edge(n);
    for (int i = 0; i < m; i++) {
        ll c;
        int s, t;
        cin >> c >> s >> t;
        s--; t--;

        edge[s].push_back({c, t});
        rev_edge[t].push_back({c, s});
    }

    vector <ll> w_dist = dijkstra(edge, w);
    vector <ll> y_dist = dijkstra(edge, y);
    vector <ll> x_dist = dijkstra(rev_edge, x);
    vector <ll> z_dist = dijkstra(rev_edge, z);

    for (int i = 0; i < n; i++) {
        edge[n].push_back({w_dist[i] + y_dist[i], i});
        edge[i].push_back({x_dist[i] + z_dist[i], n + 1});
    }

    vector <ll> ans = dijkstra(edge, n);

    ll ret = min(w_dist[x] + y_dist[z], ans[n + 1]);
    if (ret >= INF) {
        cout << "Impossible\n";
    } else {
        cout << ret << '\n';
    }

    return 0;
}