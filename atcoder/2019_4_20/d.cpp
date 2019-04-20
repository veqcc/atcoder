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
const ll MOD = 998244353;

void add(ll& a, ll b) { a = (a+b) % MOD; }
void mul(ll& a, ll b) { a = (a*b) % MOD; }

int main() {
    int N, A[300];
    cin >> N;
    int sm = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sm += A[i];
    }

    const int MX = 300 * 300;
    static ll dp[301][MX + 301], sub[301][MX + 301];
    dp[0][0] = 1;
    sub[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= MX; j++) {
            add(dp[i + 1][j + A[i]], dp[i][j]);
            add(dp[i + 1][j], 2 * dp[i][j]);
            add(sub[i + 1][j + A[i]], sub[i][j]);
            add(sub[i + 1][j], sub[i][j]);
        }
    }

    ll ng = 0;
    for (int j = (sm + 1) / 2; j <= MX; j++) add(ng, dp[N][j]);
    if (sm % 2 == 0) add(ng, MOD - sub[N][sm / 2]);
    mul(ng, 3);

    ll ans = 1;
    for (int i = 0; i < N; i++) mul(ans, 3);
    add(ans, MOD - ng);

    cout << ans << endl;
    return 0;
}