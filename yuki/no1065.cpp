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
typedef pair <double, int> P;

vector<double> dijkstra(vector<vector<P>> &edge, int s) {
    vector <double> dist(edge.size(), 1e18);
    priority_queue <P, vector<P>, greater<P>> q;
    q.push({0, s});
    dist[s] = 0;
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int cur = p.second;
        double cost = p.first;
        if (dist[cur] < cost) continue;
        for (P nxt : edge[cur]) {
            int next_node = nxt.second;
            double cost_sum = cost + nxt.first;
            if (dist[next_node] > cost_sum) {
                dist[next_node] = cost_sum;
                q.push({cost_sum, next_node});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;
    x--; y--;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i] >> q[i];

    vector<vector<P>> edge(n);
    for (int i = 0; i < m; i++) {
        int u, v;w
        cin >> u >> v;
        u--; v--;
        double diff = sqrt((p[u] - p[v]) * (p[u] - p[v]) + (q[u] - q[v]) * (q[u] - q[v]));
        edge[u].push_back({diff, v});
        edge[v].push_back({diff, u});
    }

    auto dist = dijkstra(edge, x);

    cout << fixed << setprecision(6) << dist[y] << endl;
    return 0;
}