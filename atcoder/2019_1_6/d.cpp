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
const ll INF = 1LL << 60;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, W;
    cin >> N >> W;
    int w[N];
    ll v[N];
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    ll dp[W+1];
    fill(dp, dp+W+1, 0LL);

    for (int i = 0; i < N; i++) {
        for (int j = W; j > 0; j--) {
            if (dp[j] > 0LL && j + w[i] <= W) {
                dp[j+w[i]] = max(dp[j+w[i]], dp[j] + v[i]);
            }
        }
        dp[w[i]] = max(dp[w[i]], v[i]);
    }

    cout << *max_element(dp, dp+W+1) << "\n";
    return 0;
}