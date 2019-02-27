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
typedef unsigned int uint;
using namespace std;

ll M = 1000000007LL;
ll inv[1000], fac[1000], fiv[1000];

ll comb(ll x, ll y) {
    if (x < y) return 0;
    return fac[x] * fiv[y] % M * fiv[x-y] % M;
}

int main() {
    ll R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;

    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i <= 905; i++) {
        fac[i] = fac[i - 1] * i % M; // n!
        inv[i] = inv[M % i] * (M - M / i) % M; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % M; // (n!)^-1
    }

    // 1つ離れている
    ll tmp1 = 2 * comb((X - 1) * Y, D + L) + 2 * comb(X * (Y - 1), D + L);
    tmp1 %= M;

    // 2つ離れている
    ll tmp2 = 4 * comb((X - 1) * (Y - 1), D + L) + comb((X - 2) * Y, D + L) + comb(X * (Y - 2), D + L);
    tmp2 %= M;

    // 3つ離れている
    ll tmp3 = 2 * comb((X - 2) * (Y - 1), D + L) + 2 * comb((X - 1) * (Y - 2), D + L);
    tmp3 %= M;

    // 4つ離れている
    ll tmp4 = comb((X - 2) * (Y - 2), D + L);
    tmp4 %= M;
    if (X == 1 && Y == 1) tmp4 = 0;

    ll all = comb(X * Y, D + L) - tmp1 + M + tmp2 - tmp3 + M + tmp4;
    all = all % M * comb(D + L, D) % M;

    cout << (R - X + 1) * (C - Y + 1) * all % M << "\n";
    return 0;
}