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
using namespace std;
const int INF = 1e9;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> edge(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> ans(n), dp(n, INF);

    auto dfs = [&](auto dfs, int cur, int par) -> void {
        int idx = lower_bound(dp.begin(), dp.end(), a[cur]) - dp.begin();
        int prev = dp[idx];
        dp[idx] = a[cur];

        ans[cur] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

        for (int ch : edge[cur]) {
            if (ch == par) continue;
            dfs(dfs, ch, cur);
        }

        dp[idx] = prev;
    };

    dfs(dfs, 0, -1);

    for (int x : ans) cout << x << '\n';
    return 0;
}