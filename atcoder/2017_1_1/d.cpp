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
const int INF = 1 << 30;

int dp[1 << 21]; // 集合iを前から並べる時の最小コスト

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n];
    vector <vector<int>> sm(m, vector<int>(n + 1, 0));
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        sm[a[i]][i + 1]++;
        for (int j = 0; j < m; j++) sm[j][i + 1] += sm[j][i];
    }

    fill(dp, dp + (1 << 21), INF);

    dp[0] = 0;
    for (int i = 0; i < 1 << m; i++) {
        int l = 0;
        for (int j = 0; j < m; j++) {
            if (i & 1 << j) l += cnt[j];
        }

        for (int j = 0; j < m; j++) {
            if (i & 1 << j) continue;
            int r = l + cnt[j];
            dp[i + (1 << j)] = min(dp[i + (1 << j)], dp[i] + (r - l) - (sm[j][r] - sm[j][l]));
        }
    }

    cout << dp[(1 << m) - 1] << "\n";
    return 0;
}