#include <functional>
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

    vector <ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    ll ans = 0;
    for (int c = 1; c < n - 1; c++) {
        ll cur = 0;
        int l = 0, r = n - 1;
        while (r > c && (r % c != 0 || l < r)) {
            cur += s[l] + s[r];
            ans = max(ans, cur);
            l += c; r -= c;
        }
    }

    cout << ans << "\n";
    return 0;
}