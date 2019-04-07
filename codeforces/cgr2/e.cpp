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

    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        ans += a[i] / 3;
        a[i] %= 3;
        if (i == idx) idx = i + 1;

        while (a[i] && idx < n) {
            if (a[idx] > 1) {
                a[idx] -= 2;
                a[i]--;
                ans++;
            } else {
                idx++;
            }
        }

        if (idx == n) break;
    }

    cout << ans << "\n";
    return 0;
}