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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector <int> color(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        color[i]--;
    }

    vector<vector<int>> edge(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector <int> cnt(n);
    vector < map<int, int> > dp(n);
    vector < vector<int> > res(n);

    auto dfs = [&](auto &&dfs, int cur, int par) -> void {
        for (int ch : edge[cur]) {
            if (ch == par) continue;
            dfs(dfs, ch, cur);

            int sz = cnt[ch];
            cnt[cur] += sz;
            if (dp[ch][color[cur]]) sz -= dp[ch][color[cur]];
            res[color[cur]].push_back(sz);

            if (dp[cur].size() < dp[ch].size()) swap(dp[cur], dp[ch]);
            for (auto &p : dp[ch]) dp[cur][p.first] += p.second;
        }

        cnt[cur]++;
        dp[cur][color[cur]] = cnt[cur];
    };

    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) res[i].push_back(n - dp[0][i]);

    ll total = n * (n + 1) / 2;
    vector <ll> ans(n, total);
    for (int i = 0; i < n; i++) {
        for (ll r : res[i]) {
            ans[i] -= r * (r + 1) / 2;
        }
    }

    for (ll a : ans) cout << a << '\n';
    return 0;
}
