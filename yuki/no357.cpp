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

int n, m, score[14][14], dp[1 << 14];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int i1, i2;
        cin >> i1 >> i2 >> score[i1][i2];
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;

            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) {
                    tmp += score[k][j];
                }
            }

            dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + tmp);
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}