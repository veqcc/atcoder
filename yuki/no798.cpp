#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
ll dp[2005][2005];
// i番目まで見た時にj個買っている時の金額

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    P A[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = P(b, a);
    }

    sort(A, A+n, greater<P>());

    fill(dp[0], dp[n+1], INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + A[i].second + A[i].first * j);
        }
    }

    cout << dp[n][n/3*2 + n%3] << "\n";
    return 0;
}