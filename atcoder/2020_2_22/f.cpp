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

    int k, q;
    cin >> k >> q;

    vector <ll> D(k);
    for (int i = 0; i < k; i++) cin >> D[i];

    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;

        ll sum = 0;
        vector <ll> d(k);
        for (int i = 0; i < k; i++) {
            d[i] = D[i] % m;
            if (d[i] == 0) d[i] = m;
            sum += d[i];
        }

        sum *= ((n - 1) / k);
        for (int i = 0; i < (n - 1) % k; i++) sum += d[i];

        cout << n - 1 - ((sum + x) / m - x / m) << '\n';
    }

    return 0;
}