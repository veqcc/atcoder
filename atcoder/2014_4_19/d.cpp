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

ll dp[20][2];
// i: 上からi桁目まで見て
// j: N未満であることが確定しているか

ll digit(string s) {
    int sz = s.size();
    fill(dp[0], dp[19], 0);

    dp[0][0] = 1;
    for (int i = 0; i < sz; i++) {
        for (int d = 0; d < 10; d++) {
            if (d == 4 || d == 9) continue;

            dp[i+1][1] += dp[i][1];
            if (d == s[i] - '0') dp[i+1][0] += dp[i][0];
            if (d < s[i] - '0') dp[i+1][1] += dp[i][0];
        }
    }

    return dp[sz][0] + dp[sz][1];
}

int main() {
    ll A, B;
    cin >> A >> B;
    A--;

    cout << B - A - digit(to_string(B)) + digit(to_string(A)) << "\n";
    return 0;
}