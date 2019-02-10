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

int L;
ll A[200005], dp[200005][5];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> L;
    for (int i = 1; i <= L; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= L; i++) {
        ll mn = dp[i-1][0];
        dp[i][0] = mn + A[i];

        mn = min(mn, dp[i-1][1]);
        dp[i][1] = mn + (A[i] == 0 ? 2 : A[i] % 2);

        mn = min(mn, dp[i-1][2]);
        dp[i][2] = mn - (A[i] % 2 - 1);

        mn = min(mn, dp[i-1][3]);
        dp[i][3] = mn + (A[i] == 0 ? 2 : A[i] % 2);

        mn = min(mn, dp[i-1][4]);
        dp[i][4] = mn + A[i];
    }

    ll ret = dp[L][0];
    for (int i = 1; i < 5; i++) {
        ret = min(ret, dp[L][i]);
    }

    cout << ret << "\n";
    return 0;
}