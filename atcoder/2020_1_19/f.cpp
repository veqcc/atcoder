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

int edge[50][50];
vector <int> st[50];
ll dp[50][1 << 20];

bool dfs(int cur, int par, int goal, int idx) {
    if (cur == goal) return true;

    for (int i = 0; i < 50; i++) {
        if (i == par) continue;
        if (edge[cur][i] != -1) {
            bool ret = dfs(i, cur, goal, idx);
            if (ret) {
                st[edge[cur][i]].push_back(idx);
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    fill(edge[0], edge[n], -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a][b] = i;
        edge[b][a] = i;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dfs(u, -1, v, i);
    }

    fill(dp[0], dp[n], 0LL);
    dp[0][0] = 1LL;

    for (int i = 0; i < n - 1; i++) {
        int mask = 0;
        for (int j : st[i]) mask += (1 << j);

        for (int j = 0; j < (1 << m); j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j | mask] += dp[i][j];
        }
    }

    cout << dp[n - 1][(1 << m) - 1] << '\n';
    return 0;
}