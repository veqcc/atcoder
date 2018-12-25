#include <algorithm>
#include <iostream>
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;
    ll x[N], sm[N+1];
    sm[0] = 0LL;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        sm[i+1] = x[i] + sm[i];
    }

    for (ll q = 0; q < Q; q++) {
        ll c, d;
        cin >> c >> d;

        ll i = lower_bound(x, x+N, c - d) - x;
        ll j = lower_bound(x, x+N, c) - x;
        ll k = lower_bound(x, x+N, c + d) - x;

        ll ret = 0LL;
        ret += d * i;
        ret += c * (j - i) - (sm[j] - sm[i]);
        ret += (sm[k] - sm[j]) - c * (k - j);
        ret += d * (N - k);

        cout << ans[i] << endl;
    }

    return 0;
}