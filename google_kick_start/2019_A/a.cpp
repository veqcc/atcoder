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

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n, p;
        cin >> n >> p;

        ll s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        sort(s, s+n);

        vector <ll> sm(n+1);
        for (int i = 0; i < n; i++) sm[i+1] = sm[i] + s[i];

        ll ans = 1LL << 60;
        for (int i = p-1; i < n; i++) {
            ll cost = s[i] * p - (sm[i+1] - sm[i+1-p]);
            ans = min(ans, cost);
        }

        cout << "Case #" << t+1 << ": " << ans << '\n';
    }

    return 0;
}