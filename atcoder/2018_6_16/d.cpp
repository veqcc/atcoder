#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    ll s[8][n];
    fill(s[0], s[8], 0);
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;

        for (int j = 0 ; j < 8; j++) {
            if (j >= 4) s[j][i] -= x;
            else s[j][i] += x;

            if (j%4 == 2 || j%4 == 3) s[j][i] -= y;
            else s[j][i] += y;

            if (j%2 == 1) s[j][i] -= z;
            else s[j][i] += z;
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < 8; i++) {
        sort(s[i], s[i]+n, greater<ll>());
        ll sum = 0LL;
        for (int j = 0; j < m; j++) {
            sum += s[i][j];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}