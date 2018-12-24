#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a,b);
    return a/g*b;
}

int main() {
    int n;
    cin >> n;

    ll ans=1LL, T;
    for (int i = 0; i < n; i++) {
        cin >> T;
        ans = lcm(ans, T);
    }

    cout << ans << endl;
    return 0;
}