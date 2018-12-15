#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    ll x[n], y[n], x2[n], y2[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x2[i] = x[i], y2[i] = y[i];
    }

    sort(x2, x2+n);
    sort(y2, y2+n);

    ll ans = 2000000000LL * 2000000000LL;
    for (int xi = 0; xi < n; xi++) {
        for (int xj = xi+1; xj < n; xj++) {
            for (int yi = 0; yi < n; yi++) {
                for (int yj = yi + 1; yj < n; yj++) {
                    int count = 0;
                    ll xl = x2[xi];
                    ll xr = x2[xj];
                    ll yd = y2[yi];
                    ll yu = y2[yj];

                    for (int i = 0; i < n; i++) {
                        if (x[i]>=xl && x[i]<=xr && y[i]>=yd && y[i]<=yu) {
                            count++;
                        }
                    }

                    if (count >= k) {
                        ans = min(ans, (xr-xl)*(yu-yd));
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}