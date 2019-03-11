#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll H, W, n, m;
int cnt[2005][2005];
string s[1005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W >> n >> m;

    bool all_white = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') all_white = false;
        }
    }

    if (all_white) {
        cout << 0 << '\n';
        return 0;
    }

    int h = min(H, 2 * n);
    int w = min(W, 2 * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;

            for (int k = i; k <= h-n+i; k++) {
                cnt[k][j]++;
                cnt[k][w-m+j+1]--;
            }
        }
    }

    ll ans = 0LL;
    ll tate = 0, yoko = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            if (j) cnt[i][j] += cnt[i][j-1];
            if (cnt[i][j]) {
                ans++;
                if (i == n) tate++;
                if (j == m) yoko++;
            }
        }
    }

    ans += max(0LL, H - 2 * n) * max(0LL, W - 2 * m);
    ans += tate * max(0LL, H - 2 * n);
    ans += yoko * max(0LL, W - 2 * m);

    cout << ans << "\n";
    return 0;
}