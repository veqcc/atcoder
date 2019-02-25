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

int dp[10][2][2][2][2][2];

int main() {
    string s;
    cin >> s;
    int digit = s.size();

    dp[0][0][0][0][0][0] = 1;

    // i: 上からi桁目まで見た
    // j: N未満であることが確定しているか
    // a: すでに7を選んでいるか
    // b: すでに5を選んでいるか
    // c: すでに3を選んでいるか
    // e: すでに3,5,7のどれかを選んでいるか

    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < 2; j++) {
            int limit = j ? 9 : s[i] - '0';

            for (int d = 0; d <= limit; d++) {
                if (!(d == 7 || d == 5 || d == 3 || d == 0)) continue;

                for (int a = 0; a < 2; a++) {
                    for (int b = 0; b < 2; b++) {
                        for (int c = 0; c < 2; c++) {
                            for (int e = 0; e < 2; e++) {
                                if (e && d == 0) continue;

                                dp[i+1][j || d < limit][a || d == 7][b || d == 5][c || d == 3][e || d > 0] += dp[i][j][a][b][c][e];
                            }
                        }
                    }
                }
            }
        }
    }

    int ret = 0;
    for (int j = 0; j < 2; j++) {
        ret += dp[digit][j][1][1][1][1];
    }

    cout << ret << "\n";
    return 0;
}