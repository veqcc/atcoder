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

    int n, k;
    cin >> n >> k;

    vector <ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    sort(h.begin(), h.end());

    ll ans = 0;
    for (int i = 0; i < n - k; i++) ans += h[i];

    cout << ans << "\n";
    return 0;
}