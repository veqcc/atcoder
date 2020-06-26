#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> P;

// implement dfs twice
int tree_diameter_dfs(vector<vector<P>> &edge) {
    int n = edge.size();
    vector<int> dist(n, 0);
    auto dfs = [&](auto dfs, int cur, int par) -> void {
        for (P &e : edge[cur]) {
            if (e.first == par) continue;
            dist[e.first] = dist[cur] + e.second;
            dfs(dfs, e.first, cur);
        }
    };
    dfs(dfs, 0, -1);
    int mx = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx) {
            mx = dist[i];
            idx = i;
        }
    }
    fill(dist.begin(), dist.end(), 0);
    dfs(dfs, idx, -1);
    for (int i = 0; i < n; i++) mx = max(dist[i], mx);
    return mx;
}

int tree_diameter_dp(vector<vector<P>> &edge) {
    int n = edge.size();
    vector<int> height(n, 0);
    int mx = 0;
    auto dfs = [&](auto dfs, int cur, int par) -> void {
        for (P &e : edge[cur]) {
            if (e.first == par) continue;
            dfs(dfs, e.first, cur);
        }
        int h1 = 0, h2 = 0;
        for (P &e : edge[cur]) {
            if (e.first == par) continue;
            if (height[e.first] + e.second > h1) {
                h2 = h1;
                h1 = height[e.first] + e.second;
            } else if (height[e.first] + e.second > h2) {
                h2 = height[e.first] + e.second;
            }
        }
        height[cur] = h1;
        mx = max(mx, h1 + h2);
    };
    dfs(dfs, 0, -1);
    return mx;
}

// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
void AOJ_GRL_5_A() {
    int n;
    cin >> n;
    vector<vector<P>> edge(n);
    for (int i = 1; i < n; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[s].push_back({t, w});
        edge[t].push_back({s, w});
    }
    cout << tree_diameter_dp(edge) << endl;
    // cout << tree_diameter_dfs(edge) << endl;
}

int main() {
    AOJ_GRL_5_A();
    return 0;
}