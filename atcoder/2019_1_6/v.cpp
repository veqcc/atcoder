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

int n, x, y;
ll m, dp[100005];
vector <int> edge[100005];

void dfs(int cur, int par) {
    dp[cur] = 1LL;
    for (int child : edge[cur]) {
        if (child == par) continue;
        dfs(child, cur);
        (dp[cur] *= (dp[child] + 1LL)) %= m;
    }
}

void dfs2(int cur, int par, ll par_value) {
    int sz = edge[cur].size();
    vector <ll> left(sz+1, 1LL), right(sz+1, 1LL);
    for (int i = 0; i < sz; i++) {
        int child = edge[cur][i];
        if (child == par) left[i+1] = right[i] = par_value + 1LL;
        else left[i+1] = right[i] = dp[child] + 1LL;
    }

    for (int i = 0; i < sz; i++) {
        (left[i+1] *= left[i]) %= m;
        (right[sz - i - 1] *= right[sz - i]) %= m;
    }

    dp[cur] = right[0];
    for (int i = 0; i < sz; i++) {
        int child = edge[cur][i];
        if (child == par) continue;
        dfs2(child, cur, left[i] * right[i+1] % m);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(0, -1);
    dfs2(0, -1, 0.0);
    for (int i = 0; i < n; i++) cout << dp[i] << "\n";
    return 0;
}