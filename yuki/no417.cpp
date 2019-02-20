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

int n, m, u[205], a, b, c;
vector <P> edge[205];
int dp[205][2005]; // iを頂点とする部分木で、時間jで取ってこられる最大値

void dfs(int i, int par) {
    for (int j = 0; j <= m; j++) dp[i][j] = u[i];

    for (auto j : edge[i]) {
        int to = j.first;
        int cost = j.second * 2;
        if (to == par) continue;

        dfs(to, i);
        for (int k = m; k >= 0; k--) {
            for (int l = 0; l <= k - cost; l++) {
                dp[i][k] = max(dp[i][k], dp[to][l] + dp[i][k - l - cost]);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(P(b, c));
        edge[b].push_back(P(a, c));
    }

    dfs(0, -1);

    cout << dp[0][m] << "\n";
    return 0;
}