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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    int N, L, H;
    cin >> N >> L >> H;
    L--;

    int C[N];
    for (int i = 0; i < N; i++) cin >> C[i];

    ll ans = 0LL;
    for (int i = 0; i < N; i++) {
        // C[i]だけで割り切れる数を数える
        // -> C[i]で割り切れる数 - C[i]以外のもので少なくとも一つ以上割り切れる数

        vector <int> remain;
        for (int j = 0; j < N; j++) {
            if (i != j) remain.push_back(C[j]);
        }

        ll ret = 0LL;
        for (int j = 1; j < (1 << (N - 1)); j++) {
            ll l = C[i];
            for (int k = 0; k < N - 1; k++) {
                if (j >> k & 1) l = lcm(l, remain[k]);
                if (l > H) break;
            }

            if (__builtin_popcount(j) % 2 == 1) ret += H / l;
            else ret -= H / l;
        }
        ans += H / C[i] - ret;

        ret = 0LL;
        for (int j = 1; j < (1 << (N - 1)); j++) {
            ll l = C[i];
            for (int k = 0; k < N - 1; k++) {
                if (j >> k & 1) l = lcm(l, remain[k]);
                if (l > L) break;
            }

            if (__builtin_popcount(j) % 2 == 1) ret += L / l;
            else ret -= L / l;
        }

        ans -= L / C[i] - ret;
    }

    cout << ans << "\n";
    return 0;
}