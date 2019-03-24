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
ll dp[105][4][4][4];
// A C T G

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == 0 && j == 3 && i == 1) continue; // AGC
                if (k == 0 && j == 1 && i == 3) continue; // ACG
                if (k == 3 && j == 0 && i == 1) continue; // GAC
                dp[3][i][j][k] = 1;
            }
        }
    }

    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int x = 0; x < 4; x++) {
                        if (x == 1 && l == 3 && k == 0) continue; // AGC
                        if (x == 3 && l == 1 && k == 0) continue; // ACG
                        if (x == 1 && l == 0 && k == 3) continue; // GAC
                        if (x == 1 && k == 3 && j == 0) continue; // AG?C
                        if (x == 1 && l == 3 && j == 0) continue; // A?GC

                        (dp[i][x][l][k] += dp[i-1][l][k][j]) %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                (ans += dp[n][j][k][l]) %= MOD;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}