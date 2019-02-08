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
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int c[m];
    fill(c, c+m, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        c[a]++;
    }

    int dp[m+1][5][3];
    fill(dp[0][0], dp[m+1][0], 0);
    for (int i = 0; i < m; i++) {
        for (int p = 0; p < 5; p++) {
            for (int q = 0; q < 3; q++) {
                for (int s = 0; s < 3; s++) {
                    if (p + s > c[i]) continue;
                    int tmp = (c[i] - p - s) / 3;
                    dp[i+1][q+s][s] = max(dp[i+1][q+s][s], dp[i][p][q] + s + tmp);
                }
            }
        }
    }

    cout << dp[m][0][0] << "\n";
    return 0;
}