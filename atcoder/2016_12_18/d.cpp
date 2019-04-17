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
using namespace std;

const ll MOD = 1e9+7;
ll dp[61][3];
// uのiビット目以降を確定させたとき、(N>>i)-(v>>i)がjとなる場合の数

void add(ll &a, ll b) {
    a = (a + b) % MOD;
}

int nth_bit(ll n, int i){
    return (n >> i) & 1;
}

int main() {
    ll n;
    cin >> n;

    dp[60][0] = 1;
    for (int i = 59; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int tmp = min(2, 2 * j + nth_bit(n, i) - k);
                if (tmp >= 0) add(dp[i][tmp], dp[i+1][j]);
            }
        }
    }

    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << "\n";
    return 0;
}