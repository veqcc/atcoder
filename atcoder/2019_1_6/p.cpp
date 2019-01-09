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

ll mod = 1000000007;
vector <int> G[100005];
ll dp[100005][2];
ll ret = 0LL;

void dfs(int x) {
    bool all = true;
    for (int i = 0; i < G[x].size(); i++) {
        if (dp[G[x][i]][0] > 0LL) continue;

        dp[G[x][i]][0] = (dp[x][0] + dp[x][1]) % mod;
        dp[G[x][i]][1] = dp[x][0];
        dfs(G[x][i]);
        all = false;
    }

    if (all) {
        ret += dp[x][0] + dp[x][1];
        ret %= mod;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp[0][0] = dp[0][1] = 1;
    dfs(0);

    cout << ret << "\n";
    return 0;
}