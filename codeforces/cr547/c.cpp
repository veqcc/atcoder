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

    ll q[n-1];
    vector <ll> p(n, 1);
    ll mn = 1;
    for (int i = 0; i < n - 1; i++) {
        cin >> q[i];
        p[i+1] = p[i] + q[i];
        mn = min(mn, p[i+1]);
    }

    map <ll, int> mp;
    for (int i = 0; i < n; i++) {
        p[i] += 1 - mn;
        mp[p[i]]++;
    }

    for (ll i = 1; i <= n; i++) {
        if (mp[i] != 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int x : p) cout << x << " ";

    cout << "\n";
    return 0;
}