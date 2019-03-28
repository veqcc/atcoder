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

double dp[1 << 17];
// 集合iを倒す回数の期待値

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ret += 1 << x;
    }

    for (int i = 1; i < 1 << 16; i++) {
        double mn = (double)1e9;

        for (int j = 0; j < 14; j++) {
            // j, j+1, j+2に落ちるとする

            int cnt = 3;
            double sm = 3.0;

            for (int k = j; k < j+3; k++) {
                if (i & 1 << k) {
                    sm += dp[i ^ (1 << k)];
                } else {
                    cnt--;
                }
            }

            if (cnt > 0) {
                mn = min(mn, sm / (double)cnt);
            }
        }

        dp[i] = mn;
    }

    cout << fixed << setprecision(10) << dp[ret] << "\n";
    return 0;
}