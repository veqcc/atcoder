#include <iostream>
using namespace std;
typedef long long ll;

// ax + by = gcd(a, b) なるx,yを計算する
// O(logN)
ll extGCD(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        d = extGCD(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
void AOJ_NTL_1_E() {
    ll a, b, x, y;
    cin >> a >> b;
    extGCD(a, b, x, y);
    cout << x << " " << y << "\n";
}

int main() {
    AOJ_NTL_1_E();
    return 0;
}