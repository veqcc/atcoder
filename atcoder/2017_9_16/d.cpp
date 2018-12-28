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

struct edge {
    ll from;
    ll to;
    ll cost;
};

typedef pair <ll, ll> P;
const ll INF = 1LL << 40, V = 300;
ll n, d[V];
vector <edge> G[V];

bool compareTwoEdge(edge e1, edge e2) {
    return e1.cost < e2.cost;
}

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P>> q;
    fill(d, d+V, INF);
    d[s] = 0;
    q.push(P(0, s));

    while (!q.empty()) {
        P p = q.top();
        q.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<edge> vec;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            edge e = {i, j, a[i][j]};
            vec.push_back(e);
        }
    }

    sort(vec.begin(), vec.end(), compareTwoEdge);

    ll ans = 0LL;
    for (int i = 0; i < vec.size(); i++) {
        edge e = vec[i];
        dijkstra(e.from);
        if (d[e.to] > e.cost) {
            G[e.from].push_back(e);
            edge e2 = {e.to, e.from, e.cost};
            G[e.to].push_back(e2);
            ans += e.cost;
        } else if (d[e.to] < e.cost) {
            ans = -1LL;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}