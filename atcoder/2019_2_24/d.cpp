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

int main() {
    int a, b, q, idx;
    cin >> a >> b >> q;

    ll s[a], t[b], x;
    for (int i = 0; i < a; i++) cin >> s[i];
    for (int i = 0; i < b; i++) cin >> t[i];

    for (int i = 0; i < q; i++) {
        cin >> x;

        vector <ll> shrine, temple;

        idx = lower_bound(s, s + a, x) - s;
        if (idx < a) shrine.push_back(s[idx]);
        if (idx > 0) shrine.push_back(s[idx - 1]);

        idx = lower_bound(t, t + b, x) - t;
        if (idx < b) temple.push_back(t[idx]);
        if (idx > 0) temple.push_back(t[idx - 1]);

        ll mn = 1LL << 60;
        for (ll v : shrine) {
            for (ll u : temple) {
                mn = min({mn, abs(x - u) + abs(u - v), abs(x - v) + abs(u - v)});
            }
        }

        cout << mn << "\n";
    }

    return 0;
}