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

bool dp[105][100005];
// i問目まで見たときに、得点がjであるようなものが存在するか

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        for (int j = 0; j < 100005; j++) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
                dp[i+1][j+p] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100005; i++) {
        if (dp[n][i]) ans++;
    }

    cout << ans << "\n";
    return 0;
}