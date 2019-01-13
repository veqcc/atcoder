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

const ll mod = 1000000007LL;
ll dp[10001][2][100];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    int D;
    cin >> s >> D;

    int l = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 2; j++) {
            int x = j ? 9 : s[i] - '0';
            for (int d = 0; d <= x; d++) {
                for (int k = 0; k < D; k++) {
                    dp[i+1][j || d < x][(k+d)%D] += dp[i][j][k];
                    dp[i+1][j || d < x][(k+d)%D] %= mod;
                }
            }
        }
    }

    cout << (dp[l][0][0] + dp[l][1][0] - 1 + mod) % mod << "\n";
    return 0;
}