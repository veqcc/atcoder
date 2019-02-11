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

int dp[1005][1005];

int main() {
    string s1 = "abcbdab";
    string s2 = "bdcaba";

    // LCS
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout << "  ";
    for (int i = 0; i < s2.size(); i++) {
        cout << s2[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
        for (int j = 0; j < s2.size(); j++) {
            cout << dp[i+1][j+1] << " ";
        }
        cout << "\n";
    }

    return 0;
}