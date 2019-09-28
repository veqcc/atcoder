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
const ll INF = 1LL << 60;
typedef pair <ll, int> P;

struct Station {
    int to;
    ll cost, start;
};

ll dijkstra(vector<vector<Station>> &edge, int s, int t) {
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

        for (Station e : edge[cur]) {
            ll cost_sum = cost;
            if (cost % e.start != 0) cost_sum += e.start - cost % e.start;
            cost_sum += e.cost;

            if (dist[e.to] > cost_sum) {
                dist[e.to] = cost_sum;
                q.push({cost_sum, e.to});
            }
        }
    }

    return dist[t];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    ll k, c, d;
    cin >> n >> m >> k;

    vector <ll> change(n);
    for (int i = 1; i < n - 1; i++) cin >> change[i];

    vector<vector<Station>> edge(n);
    while (m--) {
        cin >> a >> b >> c >> d;
        a--; b--;

        edge[a].push_back({b, c + change[b], d});
        edge[b].push_back({a, c + change[a], d});
    }

    ll ans = dijkstra(edge, 0, n-1);
    if (ans > k) ans = -1;

    cout << ans << "\n";
    return 0;
}