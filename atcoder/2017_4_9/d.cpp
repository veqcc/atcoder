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

int n, u, v;
vector <int> edge[150005];
double dp[150005];

void dfs(int cur, int par) {
    int sz = edge[cur].size();
    if (par >= 0) sz--;
    for (auto child : edge[cur]) {
        if (child == par) continue;
        dfs(child, cur);
        dp[cur] += (dp[child] + 1.0) / (double)sz;
    }
}

void dfs2(int cur, int par, double par_e) {
    dp[cur] = 0.0;
    double sz = (double)(edge[cur].size());
    for (auto child : edge[cur]) {
        if (child == par) dp[cur] += (par_e + 1.0) / sz;
        else dp[cur] += (dp[child] + 1.0) / sz;
    }

    for (auto child : edge[cur]) {
        if (child == par) continue;
        double next_par_e;
        if (par == -1 && sz == 1.0) next_par_e = 0.0;
        else next_par_e = (dp[cur] * sz - (dp[child] + 1.0)) / (sz - 1.0);
        dfs2(child, cur, next_par_e);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(0, -1);
    dfs2(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(12) << dp[i] << "\n";
    }

    return 0;
}