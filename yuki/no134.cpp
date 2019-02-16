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

int n;
double sx, sy, x[13], y[13], w[13], dp[1 << 13][13];

double time(double weight) {
    return (weight + 100.0) / 120.0;
}

double manhattan(double x1, double x2, double y1, double y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin >> sx >> sy >> n;
    double w_sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i];
        w_sm += w[i];
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = w[i] + time(w_sm) * manhattan(sx, x[i], sy, y[i]);
    }

    for (int i = 1; i < (1 << n); i++) {
        // 今の重さ
        double weight = 0.0;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                weight += w[j];
            }
        }

        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;

            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) continue;

                int l = i | (1 << k);
                double cost = w[k] + time(weight) * manhattan(x[j], x[k], y[j], y[k]);
                dp[l][k] = dp[l][k] ? min(dp[l][k], dp[i][j] + cost) : dp[i][j] + cost;
            }
        }
    }

    double mn = 1000000000.0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, dp[(1 << n) - 1][i] + time(0.0) * manhattan(sx, x[i], sy, y[i]));
    }

    cout << fixed << setprecision(10) << mn << "\n";
    return 0;
}