#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M;

    int a[M];
    int b[M];
    for (int i = 0; i < M; i++) {
        int ta, tb;
        cin >> ta >> tb;
        ta--; tb--;
        a[i] = ta;
        b[i] = tb;
    }

    cin >> Q;
    int dp[N][11];
    int color[Q];
    fill(dp[0], dp[N-1]+11, 0);
    for (int i = 0; i < Q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        dp[v][d] = i + 1;
        color[i] = c;
    }

    for (int i = 10; i > 0; i--) {
        for (int m = 0; m < M; m++) {
            dp[a[m]][i-1] = max(dp[a[m]][i-1], dp[b[m]][i]);
            dp[b[m]][i-1] = max(dp[b[m]][i-1], dp[a[m]][i]);
        }

        for (int n = 0; n < N; n++) {
            dp[n][i-1] = max(dp[n][i], dp[n][i-1]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (dp[i][0] > 0) {
            cout << color[dp[i][0] - 1] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}