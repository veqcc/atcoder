#include <algorithm>
#include <iostream>
#include <iomanip>
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], bit[n];
    map <int, int> mp[2];
    mp[1][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            bit[i] = a[i];
        } else {
            bit[i] = a[i] ^ bit[i-1];
        }
        mp[i%2][bit[i]]++;
    }

    ll ans = 0LL;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < mp[j].size(); i++) {
            ans += (ll)mp[j][i] * (ll)(mp[j][i] - 1) / 2LL;
        }
    }

    cout << ans << "\n";
    return 0;
}