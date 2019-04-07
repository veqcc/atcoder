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

    ll n;
    cin >> n;

    ll s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s, s+n);

    vector <ll> diff(n-1);
    for (int i = 0; i < n-1; i++) diff[i] = s[i+1] - s[i];

    sort(diff.begin(), diff.end());

    vector <ll> sm(1, 0);
    for (int i = 0; i < n-1; i++) {
        if (sm[i] > (1LL << 60)) break;
        sm.push_back(diff[i]);
        sm[i+1] += sm[i];
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;
        r = r - l + 1;

        ll idx = lower_bound(diff.begin(), diff.end(), r) - diff.begin();
        cout << sm[idx] + r * (n - idx) << " ";
    }

    return 0;
}