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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, k;
    cin >> h >> w >> k;

    vector <string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int ans = 1e9;
    for (int i = 0; i < (1 << (h - 1)); i++) {
        int cur = 0;
        vector <int> mp(h);
        int x = 0;
        for (int j = 0; j < h - 1; j++) {
            if (i & (1 << j)) {
                cur++;
                mp[j + 1] = j + 1;
                x = j + 1;
            } else {
                mp[j + 1] = x;
            }
        }

        bool possible = true;
        vector <int> sum(h), now(h);
        for (int j = 0; j < w; j++) {
            for (int l = 0; l < h; l++) {
                if (s[l][j] == '1') {
                    now[mp[l]]++;
                }
            }

            bool div = false;
            for (int l = 0; l < h; l++) {
                if (sum[l] + now[l] > k) {
                    div = true;
                }
                if (now[l] > k) {
                    possible = false;
                }
            }

            if (div) {
                cur++;
                for (int l = 0; l < h; l++) {
                    sum[l] = now[l];
                    now[l] = 0;
                }
            } else {
                for (int l = 0; l < h; l++) {
                    sum[l] += now[l];
                    now[l] = 0;
                }
            }
        }

        if (possible) {
            ans = min(ans, cur);
        }
    }

    cout << ans << "\n";
    return 0;
}