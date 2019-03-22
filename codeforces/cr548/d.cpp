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

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll m;
    cin >> m;

    ll ans = 0;
    int cnt = 0;
    for (ll i = 2; i <= m; i++) {
        auto mp = prime_factor(i);
        bool flag = true;
        ll c = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->second > 1) {
                flag = false;
                break;
            }
            c++;
        }

        c = (c % 2 * 2) - 1;
        if (flag) {
            if (c == 1) cnt++;
            else cnt--;
            ans += c * m * pow_mod(m - m/i, MOD - 2, MOD) % MOD;
            if (ans < 0) ans += MOD;
        }
    }

    ans = (ans - cnt + 1 + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}