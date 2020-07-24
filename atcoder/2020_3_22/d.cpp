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
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ans = 0;
    for (auto p : mp) {
        ans += p.second * (p.second - 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        cout << ans - mp[a[i]] + 1 << endl;
    }

    return 0;
}