#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
void AOJ_NTL_1_C() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << '\n';
}

int main() {
    AOJ_NTL_1_C();
    return 0;
}