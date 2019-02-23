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

int n, a, b, dp[100005];
vector <int> edge[100005];

void dfs(int cur, int par) {
    for (int child : edge[cur]) {
        if (child == par) continue;
        dfs(child, cur);
        if (!dp[child]) dp[cur]++;
    }
}

void dfs2(int cur, int par, bool par_win) {
    dp[cur] = 0;
    for (int child : edge[cur]) {
        if (child == par) {
            if (par_win) dp[cur]++;
        } else {
            if (!dp[child]) dp[cur]++;
        }
    }

    for (int child : edge[cur]) {
        if (child == par) continue;
        bool next_par_win = (dp[cur] - (dp[child] == 0 ? 1 : 0)) == 0;
        dfs2(child, cur, next_par_win);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0, -1);
    dfs2(0, -1, false);

    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) ans.push_back(i + 1);
    }

    cout << ans.size() << "\n";
    for (int ret : ans) cout << ret << "\n";
    return 0;
}