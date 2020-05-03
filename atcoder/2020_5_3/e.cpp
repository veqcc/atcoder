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

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        ans += mp[i + 1 - a[i]];
        mp[a[i] + i + 1]++;
    }

    cout << ans << "\n";
    return 0;
}