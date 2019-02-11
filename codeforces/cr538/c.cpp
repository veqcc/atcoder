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

// 素因数分解
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for (ll i = 2LL; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll n, b;
    cin >> n >> b;
    map <ll, ll> mp = prime_factor(b);
    map <ll, ll> :: iterator itr;
    ll ans = 1LL << 60;
    for (itr = mp.begin(); itr != mp.end(); ++itr) {
        ll x = itr->first;
        ll c = itr->second;
        ll tmp = 0LL;
        while (true) {
            tmp += n / x;
            if (x > n / itr->first) {
                break;
            }
            x *= itr->first;
        }

        ans = min(ans, tmp / c);
    }

    cout << ans << "\n";
    return 0;
}