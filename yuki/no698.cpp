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

int n, a[14], dp[1 << 14];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (i & (1 << j)) continue;
                if (i & (1 << k)) continue;

                int l = i + (1 << j) + (1 << k);
                dp[l] = max(dp[l], dp[i] + (a[j] ^ a[k]));
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}