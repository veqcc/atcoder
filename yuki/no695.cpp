#include <functional>
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
typedef pair <ll, ll> P;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 拡張Euclidの互除法
// ap + bq = gcd(a, b) となるp,qを求め、return d = gcd(a,b)
ll extGcd(ll a, ll b, ll &p, ll &q) {
    ll d = a;
    if (b == 0) {
        p = 1;
        q = 0;
    } else {
        d = extGcd(b, a % b, q, p);
        q -= (a / b) * p;
    }
    return d;
}

// Chinese Remainder Theorem
// 解あり -> x = r mod m なら return (r, m)
// 解なし -> return (-1, -1)
P CRT(vector <ll> &b, vector <ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < b.size(); i++) {
        ll p, q;
        ll d = extGcd(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return {-1, -1};
        ll tmp = (b[i] - r) / d * p % (m[i] / d); // s = (b1 - b2) / d
        r += M * tmp; // x = r + s * M * p の形
        M *= m[i] / d; // mod を lcm に更新
    }
    return {mod(r, M), M};
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];

    vector <ll> MOD = {168647939, 592951213};
    vector <ll> b(2, 0);
    for (int i = 0; i < 2; i++) {
        vector <int> dp(10000005);
        dp[0] = 1;
        for (int j = 1; j <= n / 2; j++) {
            for (auto v : x) {
                if (j - v >= 0) {
                    (dp[j] += dp[j - v]) %= MOD[i];
                }
            }
        }

        for (int j = 0; j <= n / 2; j++) {
            for (auto v : x) {
                if (j + v > n / 2 && j + v <= n - 1) {
                    (b[i] += (ll)dp[j] * (ll)dp[n - 1 - j - v]) %= MOD[i];
                }
            }
        }
    }

    P p = CRT(b, MOD);
    cout << p.first << "\n";
    return 0;
}