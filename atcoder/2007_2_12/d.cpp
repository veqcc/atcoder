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

struct TopologicalSort {
    int n;
    vector <vector<int>> G;
    vector <bool> used;
    vector <int> indeg; // 入次数
    vector <int> p;

    TopologicalSort(int sz) : n(sz), G(n), used(n), indeg(n), p(0) {}

    void add_edge(int from, int to) {
        G[from].push_back(to);
    }

    void bfs(int s) {
        queue <int> q;
        q.push(s);
        used[s] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);

            for (int u : G[v]) {
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
            for (int v : G[i]) {
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

    bool connected(int a, int b) {
        for (int v : G[a]) {
            if (v == b) return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int a[m], b[m];
    TopologicalSort ts(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        ts.add_edge(a[i], b[i]);
    }

    vector <int> ans = ts.build();

    int unique = 0;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << "\n";

        if (i) {
            if (!(ts.connected(ans[i-1], ans[i]))) {
                unique = 1;
            }
        }
    }

    cout << unique << "\n";
    return 0;
}