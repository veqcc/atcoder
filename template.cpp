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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << n << "\n";
    return 0;
}


// gcd lcm
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

// numのpow乗をmodで計算する
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}


vector < pair<int,int> > vec;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}
int main3() {
    for (int i = 0; i < n; i++) vec.push_back(make_pair(i, i+1));
    // sort by first element asc
    sort(vec.begin(), vec.end());
    // sort desc ?
    sort(vec.begin(), vec.end(), greater<int>());
    // sort by second element asc by user defined function
    sort(vect.begin(), vect.end(), sortbysec);
}


// extended Euclid
// ap+bq=gcd(a,b) -> (p, q) & returns d=gcd(a, b)
ll extGCD(ll a, ll b, ll &p, ll &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    ll d = extGCD(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// Chinese Remainder Theorem
// when x = b1 (mod m1)
//      x = b2 (mod m2)
//      m1 * p + m2 * q = d = gcd(m1, m2)
// then x = b1 + m1 * (b1 - b2) / d * p
// if x=r(mod m), returns (r, m)
pair<ll, ll> CRT(const vector<ll> &b, const vector<ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int) b.size(); i++) {
        ll p, q;
        ll d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return make_pair((r % M + M) % M, M);
}


// acos returns the inverse cosine of a number (argument) in radians
const double pi = acos(-1.0); // π
// atan2 returns tangent inverse of (y/x)
