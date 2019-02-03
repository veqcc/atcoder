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
    ll k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0LL;
    for (int i = 40; i >= -1; i--) { // i桁目でkと変わる
        if (i != -1 && !(k & (1LL << i))) {
            continue;
        }

        ll tmp = 0LL;
        for (int j = 40; j >= 0; j--) {
            ll mask = 1LL << j;
            int count = 0;
            for (int l = 0; l < n; l++) {
                if (a[l] & mask) {
                    count++;
                }
            }

            if (j > i) {
                if (k & mask) {
                    tmp += mask * (n - count);
                } else {
                    tmp += mask * count;
                }
            } else if (j == i) {
                tmp += mask * count;
            } else {
                tmp += mask * max(count, n - count);
            }
        }

        ans = max(ans, tmp);
    }

    cout << ans << "\n";
    return 0;
}