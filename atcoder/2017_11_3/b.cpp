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
using namespace std;

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

    int n;
    ll z, a;
    cin >> n >> z;

    ll ans = 1LL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = lcm(ans, gcd(z, a));
    }

    cout << ans << "\n";
    return 0;
}