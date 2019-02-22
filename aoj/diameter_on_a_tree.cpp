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

typedef pair<int, int> P;

vector <P> edge[100005];
int dp[100005];

void dfs(int cur, int par) {
    for (auto i : edge[cur]) {
        int child = i.first;
        if (child == par) continue;

        dfs(child, cur);
        dp[cur] = max(dp[cur], dp[child] + i.second);
    }
}

void dfs2(int cur, int par, int par_cost) {
    vector <P> costs;
    costs.push_back(P(0, -1));
    for (auto i : edge[cur]) {
        int child = i.first;
        int cost = i.second;
        if (child == par) costs.push_back(P(par_cost + cost, par));
        else costs.push_back(P(dp[child] + cost, child));
    }

    sort(costs.begin(), costs.end());
    reverse(costs.begin(), costs.end());

    dp[cur] = costs[0].first + costs[1].first;

    for (auto i : edge[cur]) {
        int child = i.first;
        int cost = i.second;
        if (child == par) continue;
        dfs2(child, cur, costs[costs[0].second == child].first);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].push_back(P(b, w));
        edge[b].push_back(P(a, w));
    }

    dfs(0, -1);
    dfs2(0, -1, 0);

    cout << *max_element(dp, dp+n) << "\n";
    return 0;
}