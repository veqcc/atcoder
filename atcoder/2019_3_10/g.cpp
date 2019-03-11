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

const ll inf = 1LL << 60;
ll table[16][16];
ll dp[1 << 16];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // i -> j の順に選んだ時に増える不満
            ll discontent = 0;
            int j_count = 0;
            for (int k = 0; k < m; k++) {
                if (a[k] == i) discontent += j_count;
                if (a[k] == j) j_count++;
            }

            table[i][j] = discontent;
        }
    }

    fill(dp, dp+(1 << n), inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) dp[1 << i] = 0;

    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;

            ll sm = 0;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (!(i & (1 << k))) continue;
                sm += table[k][j];
            }

            dp[i] = min(dp[i], dp[i - (1 << j)] + sm);
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}