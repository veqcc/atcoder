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

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll n;
    cin >> n;
    auto mp = prime_factor(n);
    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first == 1) continue;
        int cur = 1;
        while (itr->second >= cur) {
            itr->second -= cur;
            cur++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}