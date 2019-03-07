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
using namespace std;

const ll MOD = 1e9+7;

string S, T;
int n;
int nxt[2005][26], nxt_reverse[2005][26]; // i文字目以降で最初に文字cが登場するidx
ll dp[2005][2005]; // Sの0~i-1文字目と、Tの0~j-1文字目を使ってできる回文数 (i-1, j-1を必ず含む)

int main() {
    cin >> S;
    n = S.size();
    T = S;
    reverse(T.begin(), T.end());

    fill(nxt[0], nxt[n+1], n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i+1][j];
        }
        nxt[i][S[i] - 'a'] = i;
    }

    fill(nxt_reverse[0], nxt_reverse[n+1], n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt_reverse[i][j] = nxt_reverse[i+1][j];
        }
        nxt_reverse[i][T[i] - 'a'] = i;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 26; k++) {
                int s_idx = nxt[i][k];
                int t_idx = nxt_reverse[j][k];
                if (s_idx + t_idx + 2 > n) continue;
                (dp[s_idx + 1][t_idx + 1] += dp[i][j]) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 1;
            for (int k = 0; k < 26; k++) {
                if (nxt[i][k] + 1 + j <= n) cnt++;
            }
            (ans += dp[i][j] * cnt) %= MOD;
        }
    }

    cout << ans - 1 << "\n";
    return 0;
}