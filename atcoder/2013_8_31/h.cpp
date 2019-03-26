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

int dp[55][55][20005];
// j種類の色を使っていて、最後に使った色がkで、重さがwである時の、価値の最大値。

struct bag {
    int w, v, c;
    bool operator<(bag const &b) const {
        return c < b.c;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, W, C;
    cin >> n >> W >> C;

    vector <bag> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].w >> vec[i].v >> vec[i].c;
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        for (int j = C; j >= 1; j--) {
            for (int k = 1; k <= 50; k++) {
                for (int l = W; l >= 1; l--) {
                    if (dp[j][k][l] == 0) continue;
                    if (vec[i].c == k) {
                        dp[j][k][l + vec[i].w] = max(dp[j][k][l + vec[i].w], dp[j][k][l] + vec[i].v);
                    } else {
                        dp[j+1][vec[i].c][l + vec[i].w] = max(dp[j+1][vec[i].c][l + vec[i].w], dp[j][k][l] + vec[i].v);
                    }
                }
            }
        }
        dp[1][vec[i].c][vec[i].w] = max(dp[1][vec[i].c][vec[i].w], vec[i].v);
    }

    int mx = 0;
    for (int j = 0; j <= C; j++) {
        for (int k = 1; k <= 50; k++) {
            for (int l = 0; l <= W; l++) {
                mx = max(mx, dp[j][k][l]);
            }
        }
    }

    cout << mx << "\n";
    return 0;
}