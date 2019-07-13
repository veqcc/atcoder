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

    int n, m;
    cin >> n >> m;

    bool connected[n][n];
    fill(connected[0], connected[n], false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        connected[x][y] = true;
        connected[y][x] = true;
    }

    int ans = 1;
    for (int i = 0; i < (1 << n); i++) {
        bool f = true;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (i & (1 << j) && i & (1 << k)) {
                    if (!connected[j][k]) {
                        f = false;
                        break;
                    }
                }
            }

            if (!f) break;
        }

        if (f) {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    cout << ans << "\n";
    return 0;
}