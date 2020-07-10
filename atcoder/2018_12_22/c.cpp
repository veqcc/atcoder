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

map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll n, p;
    cin >> n >> p;
    auto mp = prime_factor(p);
    ll ans = 1;
    for (auto &itr : mp) {
        while (itr.second >= n) {
            itr.second -= n;
            ans *= itr.first;
        }
    }
    cout << ans << endl;
    return 0;
}