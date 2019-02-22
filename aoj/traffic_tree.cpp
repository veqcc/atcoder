#include <algorithm>
#include <iostream>
#include <iomanip>
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

vector <int> edge[100005];
int dp[100005];

void dfs(int cur, int par) {
    for (auto child : edge[cur]) {
        if (child == par) continue;
        dfs(child, cur);
        dp[cur] = max(dp[cur], dp[child] + 1);
    }
}

void dfs2(int cur, int par, int par_depth) {
    vector <int> depth;
    depth.push_back(0);
    for (auto child : edge[cur]) {
        if (child == par) depth.push_back(par_depth + 1);
        else depth.push_back(dp[child] + 1);
    }

    sort(depth.begin(), depth.end(), greater<int>());
    dp[cur] = depth[0];

    for (auto child : edge[cur]) {
        if (child == par) continue;
        dfs2(child, cur, depth[depth[0] == dp[child] + 1]);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(0, 0);
    dfs2(0, 0, 0);

    for (int i = 0; i < n; i++) {
        cout << (n - 1) * 2 - dp[i] << "\n";
    }

    return 0;
}