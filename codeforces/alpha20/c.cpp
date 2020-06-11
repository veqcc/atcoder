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

vector <ll> dijkstra(vector<vector<P>> &edge, int s) {
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
    int n, m;
    cin >> n >> m;
    vector<vector<P>> edge(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--; b--;
        edge[a].push_back({w, b});
        edge[b].push_back({w, a});
    }
    auto dist = dijkstra(edge, 0);
    if (dist[n - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans(1, n);
    int cur = n - 1;
    while (cur != 0) {
        for (P nxt : edge[cur]) {
            if (dist[cur] == dist[nxt.second] + nxt.first) {
                cur = nxt.second;
                ans.push_back(cur + 1);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) cout << a << ' ';
    return 0;
}