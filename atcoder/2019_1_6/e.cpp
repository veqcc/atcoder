#include <algorithm>
#include <iostream>
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
const int INF = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    int w[N], v[N];
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    int dp[100005];
    fill(dp, dp+100005, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 100000; j > 0; j--) {
            if (dp[j] < INF && dp[j] + w[i] <= W) {
                dp[j+v[i]] = min(dp[j+v[i]], dp[j] + w[i]);
            }
        }
        dp[v[i]] = min(dp[v[i]], w[i]);
    }

    for (int i = 100000; i > 0; i--) {
        if (dp[i] < INF) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}