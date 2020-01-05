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

    ll n, mod;
    cin >> n >> mod;

    vector <ll> factorial(n + 1, 1LL);
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (n - i) * factorial[i + 1] % mod * factorial[n - i] % mod;
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}