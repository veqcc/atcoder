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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    ll ans = 0;

    if (p == 2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0) {
                ans += i + 1;
            }
        }
    } else {
        map <ll, ll> mp;

        ll cur = 0;
        mp[cur]++;
        for (int i = n - 1; i >= 0; i--) {
            ll tmp = pow_mod(10, n - i - 1, p);
            tmp = tmp * (s[i] - '0') % p;
            cur = (cur + tmp) % p;
            mp[cur]++;
        }

        ans += mp[0] * (mp[0] - 1) / 2;
        for (int i = 1; i < p; i++) {
            ans += mp[i] * (mp[i] - 1) / 2;
        }
    }

    cout << ans << '\n';
    return 0;
}