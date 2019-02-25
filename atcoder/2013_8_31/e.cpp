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

const ll MOD = 1000000007LL;

ll dp[10005][100][2];
// i: 上からi桁目まで見た
// j: MODの値
// k: N未満が確定しているか

int main() {
    int D;
    string S;
    cin >> D >> S;
    int N = S.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < 2; k++) {
                int lim = k ? 9 : S[i] - '0';
                for (int d = 0; d <= lim; d++) {
                    (dp[i+1][(j+d)%D][k || d < lim] += dp[i][j][k]) %= MOD;
                }
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][0][1] + MOD - 1) % MOD << "\n";
    return 0;
}