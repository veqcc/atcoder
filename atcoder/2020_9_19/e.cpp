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
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> ord(m, -1), sum(m, -1);
    ll ans = 0, cycle_sum = 0;
    ll cycle = 0, i = 0;
    for (; i < n; i++) {
        if (ord[x] != -1) {
            cycle = i - ord[x];
            ans += x;
            cycle_sum = ans - sum[x];
            x = x * x % m;
            break;
        }

        ord[x] = i;
        ans += x;
        sum[x] = ans;
        x = x * x % m;
    }

    i++;

    if (cycle) {
        ll cycle_num = (n - i) / cycle;
        ans += cycle_num * cycle_sum;
        i += cycle * cycle_num;
    }

    for (; i < n; i++) {
        ans += x;
        x = x * x % m;
    }

    cout << ans << endl;
    return 0;
}