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

// 約数のvectorを返す
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector <ll> da = divisor(a[0]);
    vector <ll> db = divisor(b[0]);

    ll ans = 1;
    for (ll v : da) {
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (a[i] % v != 0 && b[i] % v != 0) {
                f = false;
                break;
            }
        }
        if (f) ans = max(ans, v);
    }
    for (ll v : db) {
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (a[i] % v != 0 && b[i] % v != 0) {
                f = false;
                break;
            }
        }
        if (f) ans = max(ans, v);
    }

    cout << ans << '\n';
    return 0;
}