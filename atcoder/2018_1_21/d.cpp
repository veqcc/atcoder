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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int count[2 * K][K];
    fill(count[0], count[2 * K], 0);
    for (int i = 0; i < N; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if ((x / K + y / K) % 2 == 0) {
            if (c == 'B') {
                count[x % K][y % K]++;
            } else {
                count[x % K + K][y % K]++;
            }
        } else {
            if (c == 'B') {
                count[x % K + K][y % K]++;
            } else {
                count[x % K][y % K]++;
            }
        }
    }

    for (int i = 2*K-1; i >= 0; i--) {
        for (int j = K-1; j >= 0; j--) {
            if (i == 2*K-1 && j == K-1) {
                continue;
            } else if (i == 2*K-1) {
                count[i][j] += count[i][j+1];
            } else if (j == K-1) {
                count[i][j] += count[i+1][j];
            } else {
                count[i][j] += count[i+1][j] + count[i][j+1] - count[i+1][j+1];
            }
        }
    }

    int mx = 0;
    // blackの左下が (i, j)
    for (int i = 0; i < 2*K; i++) {
        for (int j = 0; j < K; j++) {
            int ans = 0;
            if (i < K) {
                ans += count[i][j] - count[i+K][j];
                ans += count[0][0] - count[i][0] - count[0][j] + count[i][j];
                ans += count[i+K][0] - count[i+K][j];
            } else {
                ans += count[i][j];
                ans += count[i-K][0] - count[i][0] - count[i-K][j] + count[i][j];
                ans += count[0][j] - count[i-K][j];
            }
            mx = max(mx, ans);
        }
    }

    cout << mx << "\n";
    return 0;
}