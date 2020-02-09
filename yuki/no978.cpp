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
    ll p;
    cin >> n >> p;

    vector <ll> fib(n), sum(n);
    fib[0] = sum[0] = 0;
    fib[1] = sum[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = p * fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
        sum[i] = sum[i - 1] + fib[i];
        sum[i] %= MOD;
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans = (ans + fib[i] * sum[i] % MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}