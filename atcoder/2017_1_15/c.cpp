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

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    int n;
    cin >> n;

    map <int, int> mp;
    for (int i = 2; i <= n; i++) {
        auto mp2 = prime_factor(i);
        for (auto &itr : mp2) {
            mp[itr.first] += itr.second;
        }
    }

    ll ans = 1;
    for (auto &itr : mp) {
        if (itr.first == 1) continue;
        ans = ans * (itr.second + 1) % MOD;
    }

    cout << ans << endl;
    return 0;
}