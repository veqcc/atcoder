#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const ll mod = 1e9+7;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, m, x, y, w = 0LL, h = 0LL;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        w = (w + i*x - (n-i-1)*x) % mod;
    }
    for (ll i = 0; i < m; i++) {
        cin >> y;
        h = (h + i*y - (m-i-1)*y) % mod;
    }

    cout << w * h % mod << "\n";
    return 0;
}