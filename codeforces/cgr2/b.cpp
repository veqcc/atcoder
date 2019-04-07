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

    ll n, h;
    cin >> n >> h;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        vector <ll> vec(k);
        for (int i = 0; i < k; i++) vec[i] = a[i];

        sort(vec.begin(), vec.end(), greater<ll>());

        ll sm = 0;
        for (int i = 0; i < k; i += 2) sm += vec[i];

        if (sm <= h) ans = k;
    }

    cout << ans << "\n";
    return 0;
}