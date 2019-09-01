#include <algorithm>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

typedef pair <ll, ll> P;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 拡張Euclidの互除法
// ap + bq = gcd(a, b) となるp,qを求め、return d = gcd(a,b)
ll extGcd(ll a, ll b, ll &p, ll &q) {
    ll d = a;
    if (b == 0) {
        p = 1;
        q = 0;
    } else {
        d = extGcd(b, a % b, q, p);
        q -= (a / b) * p;
    }
    return d;
}

// Chinese Remainder Theorem
// 解あり -> x = r mod m なら return (r, m)
// 解なし -> return (-1, -1)
P CRT(vector <ll> &b, vector <ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < b.size(); i++) {
        ll p, q;
        ll d = extGcd(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return {-1, -1};
        ll tmp = (b[i] - r) / d * p % (m[i] / d); // s = (b1 - b2) / d
        r += M * tmp; // x = r + s * M * p の形
        M *= m[i] / d; // mod を lcm に更新
    }
    return {mod(r, M), M};
}


// verified
//  https://yukicoder.me/problems/447https://yukicoder.me/problems/447
void yuki186() {
    vector <ll> x(3), y(3);
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    P p = CRT(x, y);
    cout << (p.first == 0 ? p.second : p.first) << '\n';
}


int main() {
    yuki186();
    return 0;
}