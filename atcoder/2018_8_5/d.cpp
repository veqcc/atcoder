#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    int MOD = 1000000007;

    long long dp[100010][4] = {};
    for (int i = N; i >= 0; --i) {
        for (int j = 3; j >= 0; --j) {
            if (i == N) {
                dp[i][j] = (j == 3 ? 1 : 0);
            } else {
                dp[i][j] = dp[i+1][j] * (S[i] == '?' ? 3LL : 1LL);
                if (j < 3 && (S[i] == '?' || S[i] == "ABC"[j])) {
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
}