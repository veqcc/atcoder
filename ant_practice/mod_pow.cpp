#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const ll mod = 1000000007;

// x ^ n (mod)
// いわゆる繰り返し二乗法
ll mod_pow(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res  = res * x % mod;
    return res;
}

int main() {
    ll a = 3;
    ll b = 5;
    cout << mod_pow(a, b, mod); // 3 ^ 5 (mod)
    return 0;
}