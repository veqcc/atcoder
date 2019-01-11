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

struct TopologicalSort {
    int n;
    vector <set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort() {}
    TopologicalSort(int sz) : n(sz), G(n), used(n), indeg(n), p(0) {}

    void add_edge(int s, int t) {
        G[s].insert(t);
    }

    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u:G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }

    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int v:G[i]) {
                indeg[v]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0 && !used[i]) {
                bfs(i);
            }
        }

        return p;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> table[N];

    TopologicalSort ts(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        ts.add_edge(s, t);
        table[s].push_back(t);
    }

    auto p = ts.build();

    int dp[N];
    fill(dp, dp + N, 0);

    for (int node : p) {
        for (int next : table[node]) {
            dp[next] = max(dp[next], dp[node] + 1);
        }
    }

    int ret = -1;
    for (int i = 0; i < N; i++) {
        ret = max(ret, dp[i]);
    }

    cout << ret << endl;

    return 0;
}