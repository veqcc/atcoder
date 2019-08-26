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
    string s;
    cin >> n >> s;

    ll ans = 1;
    ll cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'B') {
            if (cur % 2 == 0) {
                cur++;
            } else {
                ans = ans * cur % MOD;
                cur--;
            }
        } else {
            if (cur % 2 == 0) {
                ans = ans * cur % MOD;
                cur--;
            } else {
                cur++;
            }
        }
    }

    if (cur != 0) {
        ans = 0;
    }

    for (ll i = 1; i <= n; i++) {
        ans = ans * i % MOD;
    }

    cout << ans << "\n";
    return 0;
}