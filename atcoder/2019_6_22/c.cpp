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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = b - a + 1;

    // cで割り切れる
    ans -= (b / c - (a - 1) / c);

    // dで
    ans -= (b / d - (a - 1) / d);

    // lcmで
    ll e = lcm(c, d);
    ans += (b / e - (a - 1) / e);

    cout << ans << "\n";
    return 0;
}