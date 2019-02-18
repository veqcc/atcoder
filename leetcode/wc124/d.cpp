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

class Solution {
public:
    bool is_square(int n) {
        for (int i = 0; i * i <= n; i++) {
            if (i * i == n) return true;
        }
        return false;
    }

    int factorial(int n) {
        if (n == 1) return 1;
        return n * factorial(n-1);
    }

    int numSquarefulPerms(vector<int> &A) {
        int n = A.size();
        bool table[n][n];
        map <int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                table[i][j] = table[j][i] = is_square(A[i] + A[j]);
            }
            mp[A[i]]++;
        }

        int dp[1 << n][n];
        fill(dp[0], dp[1 << n], 0);

        for (int i = 0; i < n; i++) {
            dp[(1 << i)][i] = 1;
        }

        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) continue;
                if (dp[i][j] == 0) continue;

                for (int k = 0; k < n; k++) {
                    if (j == k) continue;
                    if (i & (1 << k)) continue;

                    dp[i | (1 << k)][k] += dp[i][j] * table[j][k];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[(1 << n) - 1][i];
        }

        map<int, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); ++itr) {
            ans /= factorial(itr->second);
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector <int> vec = {948507270,461613425};
    cout << so.numSquarefulPerms(vec) << "\n";
    return 0;
}