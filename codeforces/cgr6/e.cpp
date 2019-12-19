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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll ans = 0;
    vector <int> a(n + 1, -1e9);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    int Q;
    cin >> Q;

    map <P, int> mp;
    vector <int> sm(n + 1);
    for (int q = 0; q < Q; q++) {
        int s, t, u;
        cin >> s >> t >> u;

        int prev = mp[P(s, t)];
        sm[u]++;
        if (sm[u] <= a[u]) ans--;

        sm[prev]--;
        if (sm[prev] < a[prev]) ans++;
        mp[P(s, t)] = u;

        cout << ans << '\n';
    }

    return 0;
}