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

int n, m, a[10], b[11], sm[1 << 10], dp[11][1 << 10];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sm[i] += a[j];
            }
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(b+1, b+m+1, greater<int>());

    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (dp[i][j] == 0) continue;
                if (j & k) continue;
                if (sm[k] > b[i+1]) continue;

                dp[i+1][j | k] = 1;
                if ((j | k) == (1 << n) - 1) {
                    cout << i + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "-1\n";
    return 0;
}