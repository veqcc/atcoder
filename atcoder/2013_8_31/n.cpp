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
typedef pair<ll, int> P;

const ll M = 1000000007LL;
vector <int> edge[1005];
ll dp[1005], C[1005][1005];

void comb_table(int N) {
    for (int i = 0; i <= N; i++) {
        C[i][0] = C[i][i] = 1LL;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
        }
    }
}

int dfs(int cur, int par) {
    dp[cur] = 1;
    int sz = 0;
    for (auto i : edge[cur]) {
        if (i == par) continue;
        int res = dfs(i, cur) + 1;
        dp[cur] = dp[cur] * dp[i] % M * C[sz + res][res] % M;
        sz += res;
    }
    return sz;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    comb_table(n);

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        dfs(i, -1);
        ans = (ans + dp[i]) % M;
    }

    cout << ans * (M + 1) / 2 % M << "\n";
    return 0;
}