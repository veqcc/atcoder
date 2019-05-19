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

// 約数のvectorを返す
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector <ll> div = divisor(n);

    ll ans = 0;

    for (ll i : div) {
        ll m = n / i - 1;
        if (m && n % m == i) {
            ans += m;
        }
    }

    cout << ans << "\n";
    return 0;
}