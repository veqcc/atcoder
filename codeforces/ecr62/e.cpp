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
const ll MOD = 998244353LL;

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

ll n, k;

// 左右がsameな文字で挟まれていて、-1がlen個ある時の当てはめ方
ll f(bool same, int len) {
    if (len == 0) {
        if (same) return 0LL;
        else return 1LL;
    }

    ll dp[len][2];
    fill(dp[0], dp[len], 0);

    if (same) {
        dp[0][0] = k-1;
        dp[0][1] = 0;
    } else {
        dp[0][0] = k-2;
        dp[0][1] = 1;
    }

    for (int i = 0; i < len-1; i++) {
        dp[i+1][1] = dp[i][0];
        dp[i+1][0] = ((k-2)*dp[i][0] + (k-1)*dp[i][1]) % MOD;
    }

    return dp[len-1][0];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    vector <int> vec[2], idx[2];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec[i%2].push_back(a);
        if (a > 0) idx[i%2].push_back(i/2);
    }

    ll ans = 1LL;
    for (int j = 0; j < 2; j++) {
        int vec_sz = vec[j].size();
        int idx_sz = idx[j].size();

        if (idx_sz) {
            (ans *= pow_mod(k-1, idx[j][0], MOD)) %= MOD;
            (ans *= pow_mod(k-1, vec_sz - idx[j][idx_sz - 1] - 1, MOD)) %= MOD;

            for (int i = 0; i < idx_sz - 1; i++) {
                bool same = vec[j][idx[j][i]] == vec[j][idx[j][i+1]];
                int len = idx[j][i+1] - idx[j][i] - 1;

                (ans *= f(same, len)) %= MOD;
            }
        } else {
            (ans *= k % MOD * pow_mod(k-1, vec_sz-1, MOD)) %= MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}