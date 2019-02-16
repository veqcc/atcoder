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

int n, m[15], dp[1 << 15];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];

    for (int i = 0; i < (1 << n); i++) {
        // 集合iを買った時の値引額
        int discount = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) discount += m[j];
        }
        discount %= 1000;

        // 新たに商品jを買う
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;

            int sm = i | (1 << j);
            int cost = max(0, m[j] - discount);
            dp[sm] = dp[sm] ? min(dp[sm], dp[i] + cost) : dp[i] + cost;
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}