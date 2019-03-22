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

int dp[1005][1005];
// 左にi個、右にj個残っている状態から、先手が取れる価値の最大値

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int A, B;
    cin >> A >> B;
    int p = (A + B) % 2;

    vector <int> a(A+1), b(B+1);
    for (int i = A; i > 0; i--) cin >> a[i];
    for (int i = B; i > 0; i--) cin >> b[i];


    for (int i = 1; i <= A; i++) {
        dp[i][0] = dp[i-1][0];
        if (i % 2 == p) dp[i][0] += a[i];
    }

    for (int i = 1; i <= B; i++) {
        dp[0][i] = dp[0][i-1];
        if (i % 2 == p) dp[0][i] += b[i];
    }

    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            if ((i+j)%2 == p) {
                dp[i][j] = max(dp[i-1][j] + a[i], dp[i][j-1] + b[j]);
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[A][B] << "\n";
    return 0;
}