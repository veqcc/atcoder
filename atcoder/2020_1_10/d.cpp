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

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }

    ll l = 1;
    for (int i = 0; i < n; i++) {
        l = lcm(l, a[i]);
        if (l > m * 2) {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if ((l / a[i]) % 2 == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << m / l - m / (l * 2) << "\n";
    return 0;
}