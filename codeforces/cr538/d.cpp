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

int n, c, dp[5005][5005];
vector <int> vec, rev;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (i > 0 && c == vec.back()) continue;
        vec.push_back(c);
    }

    n = vec.size();
    rev = vec;
    reverse(rev.begin(), rev.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i] == rev[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << n - (dp[n][n] + 1) / 2 << "\n";
    return 0;
}