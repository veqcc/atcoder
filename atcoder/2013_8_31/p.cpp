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
int N, K;
vector <int> edge[1005];
ll dp[1005][55][3]; // i以下のsubtreeで、j個のパスがあり、次数がk

void dfs(int cur, int par) {
    ll dp2[2][K+1][3]; // 子のうちx番目まで見て、l本のパスがあり、次数がm
    fill(dp2[0][0], dp2[1][K+1], 0);
    dp2[0][0][0] = 1;
    int x = 0, y = 1;
    for (int i = 0; i < edge[cur].size(); i++) {
        int child = edge[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        for (int j = K; j >= 0; j--) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < K - j + 2; l++) {
                    for (int m = 0; m < 3; m++) {
                        // 子childは次数mでパスをl個持つ 親iは次数kでパスをj個持つ
                        ll tmp = dp2[x][j][k] * dp[child][l][m] % MOD;
                        // iとchildを繋げる
                        if (m < 2 && k < 2) {
                            int path = j + l;
                            if (k == 0 && m == 0) path++;
                            if (k == 1 && m == 1) path--;
                            if (path >= 0 && path <= K) (dp2[y][path][k+1] += tmp) %= MOD;
                        }
                        // iとchildを繋げない
                        if (j + l <= K) (dp2[y][j + l][k] += tmp) %= MOD;
                    }
                }
            }
        }
        swap(x, y);
        fill(dp2[y][0], dp2[y][K+1], 0);
    }
    for (int j = 0; j <= K; j++) for (int k = 0; k < 3; k++) dp[cur][j][k] = dp2[x][j][k];
}

int main() {
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0, -1);
    cout << (dp[0][K][0] + dp[0][K][1] + dp[0][K][2]) % MOD << "\n";
    return 0;
}