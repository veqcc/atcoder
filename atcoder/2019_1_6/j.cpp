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

double dp[305][305][305];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, a=0, b=0, c=0;;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p == 1) a++;
        if (p == 2) b++;
        if (p == 3) c++;
    }

    for (int k = 0; k <= 300; k++) {
        for (int j = 0; j <= 300; j++) {
            for (int i = 0; i <= 300; i++) {
                if (i + j + k == 0) continue;
                dp[i][j][k] = N;
                if (i) dp[i][j][k] += dp[i-1][j][k] * (double)i;
                if (j) dp[i][j][k] += dp[i+1][j-1][k] * (double)j;
                if (k) dp[i][j][k] += dp[i][j+1][k-1] * (double)k;
                dp[i][j][k] /= (double)(i + j + k);
            }
        }
    }

    cout << fixed << setprecision(15) << dp[a][b][c] << "\n";
    return 0;
}