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

struct Edge {
    int to;
    ll cost;
};

vector<int> Centroid(const vector<vector<Edge>> &edge) {
    int n = edge.size();
    vector<int> centroids;
    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int cur, int par) {
        sz[cur] = 1;
        bool is_centroid = true;
        for (Edge ch : edge[cur]) {
            if (ch.to == par) continue;
            dfs(ch.to, cur);
            sz[cur] += sz[ch.to];
            if (sz[ch.to] > n / 2) is_centroid = false;
        }
        if (n - sz[cur] > n / 2) is_centroid = false;
        if (is_centroid) centroids.push_back(cur);
    };
    dfs(0, -1);
    return centroids;
}

ll total_cost[100005];

void dfs(vector<vector<Edge>> &edge, int cur, int par, ll sum) {
    total_cost[cur] = sum;
    for (Edge e : edge[cur]) {
        if (e.to == par) continue;
        dfs(edge, e.to, cur, sum + e.cost);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<Edge>> edge(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;

        edge[a].push_back(Edge{b, c});
        edge[b].push_back(Edge{a, c});
    }

    vector <int> centroids = Centroid(edge);

    ll ans = 0;
    if (centroids.size() == 2) {
        for (Edge e : edge[centroids[0]]) {
            if (e.to == centroids[1]) {
                ans -= e.cost;
            }
        }
    } else {
        ll mn = 1LL << 30;
        for (Edge e : edge[centroids[0]]) {
            mn = min(mn, e.cost);
        }
        ans -= mn;
    }

    int center = centroids[0];
    dfs(edge, center, -1, 0);

    for (int i = 0; i < n; i++) {
        ans += 2LL * total_cost[i];
    }

    cout << ans << "\n";
    return 0;
}