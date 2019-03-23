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

double dp[1 << 10][11];

double p(double x, double y) {
    return 1.0 / (1.0 + pow(10.0, (y - x) / 400.0));
}

int main() {
    int k;
    cin >> k;

    double R[1 << k];
    for (int i = 0; i < 1 << k; i++) {
        cin >> R[i];
        dp[i][0] = 1.0;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < 1 << k; i++) {
            // 第jラウンドでiと当たる可能性があるのは、
            // 第j-1ビットが異なり、j以上はsame、j-1未満はany
            int mask = 0;
            for (int l = k-1; l >= j; l--) {
                if (i & 1 << l) mask += 1 << l;
            }
            if (!(i & 1 << (j-1))) mask += 1 << (j-1);

            double sm = 0.0;
            for (int l = 0; l < (1 << (j-1)); l++) {
                sm += dp[l + mask][j-1] * p(R[i], R[l + mask]);
            }

            dp[i][j] = dp[i][j-1] * sm;
            if (j == k) cout << fixed << setprecision(9) << dp[i][k] << '\n';
        }
    }

    return 0;
}