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

const int mod = 1000000007;
int n, k, dp[2][300005];
vector <int> A;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * A[i]; j++) {
            dp[1][j] = (dp[1][j] + dp[0][j]) % mod;
            dp[1][j^A[i]] = (dp[1][j^A[i]] + dp[0][j]) % mod;
        }

        for (int j = 0; j < 2 * A[i]; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][k] << "\n";
    return 0;
}