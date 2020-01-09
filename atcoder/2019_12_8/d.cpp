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

    vector <ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    ll ans = 0LL;
    for (int i = 0; i < 60; i++) {
        ll count = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] & (1LL << i)) {
                count++;
            }
        }

        ans = (ans + (1LL << i) % MOD * count % MOD * (n - count) % MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}