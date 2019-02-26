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

int dp[10][2][10];
// i: 上からi桁目まで見た
// j: N未満であることが確定しているか
// k: 1を使った数がk回となる数字の総数

int main() {
    string S;
    cin >> S;
    int N = S.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 10; k++) {
                int lim = j ? 9 : S[i] - '0';

                for (int d = 0; d <= lim; d++) {
                    dp[i+1][j || d < lim][k + (d == 1)] += dp[i][j][k];
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 10; k++) {
            ans += dp[N][j][k] * k;
        }
    }

    cout << ans << "\n";
    return 0;
}