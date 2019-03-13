#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll INF = 1LL << 60;

struct Edge {
    int to; ll cap; int rev;
    Edge(int t, ll c, int r) : to(t), cap(c), rev(r) {}
};

struct Flow {
    vector <vector<Edge>> G;
    vector<bool> used;
    Flow(int n) : G(n), used(n, false) {}
    void add_edge(int from, int to, ll cap) {
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, 0, G[from].size() - 1));
    }
    ll dfs(int v, int t, ll f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll max_flow(int s, int t) {
        ll flow = 0;
        while (1) {
            fill(used.begin(), used.end(), false);
            ll f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ll d;
    cin >> n >> m >> d;

    int u[m], v[m];
    ll p[m], q[m], w[m];
    set <ll> st;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> p[i] >> q[i] >> w[i];
        u[i]--; v[i]--;
        st.insert(p[i]);
        st.insert(q[i] + d);
    }

    map <ll, int> mp;
    int idx = 0;
    for (auto itr = st.begin(); itr != st.end(); itr++) mp[*itr] = idx++;

    int sz = mp.size();
    Flow fl(n*sz);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz - 1; j++) {
            fl.add_edge(i*sz + j, i*sz + j + 1, INF);
        }
    }

    for (int i = 0; i < m; i++) {
        fl.add_edge(u[i] * sz + mp[p[i]], v[i] * sz + mp[q[i] + d], w[i]);
    }

    cout << fl.max_flow(0, n*sz - 1) << "\n";
    return 0;
}