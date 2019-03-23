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

double dp[105][60][60][60];

int main() {
    int n;
    ll d;
    cin >> n >> d;

    int x = 0;
    while (d % 2 == 0) {
        x++;
        d /= 2;
    }

    int y = 0;
    while (d % 3 == 0) {
        y++;
        d /= 3;
    }

    int z = 0;
    while (d % 5 == 0) {
        z++;
        d /= 5;
    }

    if (d > 1) {
        cout << 0.0 << '\n';
        return 0;
    }

    dp[0][0][0][0] = 1.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                for (int l = 0; l <= z; l++) {
                    // 1
                    dp[i + 1][j][k][l] += dp[i][j][k][l] / 6.0;

                    // 2
                    dp[i + 1][min(x, j + 1)][k][l] += dp[i][j][k][l] / 6.0;

                    // 3
                    dp[i + 1][j][min(y, k + 1)][l] += dp[i][j][k][l] / 6.0;

                    // 4
                    dp[i + 1][min(x, j + 2)][k][l] += dp[i][j][k][l] / 6.0;

                    // 5
                    dp[i + 1][j][k][min(z, l + 1)] += dp[i][j][k][l] / 6.0;

                    // 6
                    dp[i + 1][min(x, j + 1)][min(y, k + 1)][l] += dp[i][j][k][l] / 6.0;
                }
            }
        }
    }

    cout << fixed << setprecision(9) << dp[n][x][y][z] << "\n";
    return 0;
}

