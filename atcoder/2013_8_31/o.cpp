#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int MAX_N = 2000000;

ll inv[MAX_N], fac[MAX_N], fiv[MAX_N];
void COMinit() {
    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }
}
ll com(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * fiv[k] % MOD * fiv[n-k] % MOD;
}

ll dp[30][300];

int main() {
    vector <int> freg(26);
    vector <int> len(27, 0);
    for (int i = 1; i <= 26; i++) {
        cin >> freg[i-1];
        len[i] = len[i-1] + freg[i-1];
    }

    COMinit();

    dp[0][0] = 1;
    for (int i = 0; i < 26; i++) { // アルファベットのi番目を加える
        for (int j = 0; j <= len[i]; j++) { // j個の"隣"がある
            if (freg[i] == 0) {
                dp[i+1][j] = dp[i][j];
                continue;
            }

            for (int k = 0; k <= j; k++) { // k個の"隣"を解消する
                for (int l = 0; l < freg[i]; l++) { // l個の新たな"隣"を作る
                    ll x = com(j, k); // 現在のj個の隣からk個の解消する隣を選ぶ
                    ll y = com(len[i] + 1 - j, freg[i] - l - k); // "隣"でないところから選ぶ
                    ll z = com(freg[i] - 1, l);
                    dp[i+1][j-k+l] += dp[i][j] * x % MOD * y % MOD * z % MOD;
                    dp[i+1][j-k+l] %= MOD;
                }
            }
        }
    }

    cout << dp[26][0] << "\n";
    return 0;
}