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

const ll MOD = 1000000007LL;
int n, K;
vector <int> edge[2005];
ll dp[2005][2005]; // 頂点i以下のsubtreeにおいて、ちょうどj個の頂点を黒にする場合の数

int dfs(int cur, int par) {
    ll dp2[2][2005]; // 子をx番目まで見たときに、頂点i以下でちょうどj個を黒にする場合の数
    fill(dp2[0], dp2[1]+2005, 0);
    dp2[0][0] = 1;

    int sm = 1;
    int x = 0, y = 1;
    for (auto child : edge[cur]) {
        if (child == par) continue;

        int sz = dfs(child, cur);
        for (int j = 0; j <= sz; j++) {
            for (int k = 0; k < sm; k++) {
                (dp2[y][j+k] += dp2[x][k] * dp[child][j] % MOD) %= MOD;
            }
        }

        sm += sz;
        swap(x, y);
        fill(dp2[y], dp2[y]+2005, 0);
    }

    for (int i = 0; i < sm; i++) dp[cur][i] = dp2[x][i];
    dp[cur][sm] = 1;

    return sm;
}

int main() {
    cin >> n >> K;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0, -1);
    cout << dp[0][K] << "\n";
    return 0;
}