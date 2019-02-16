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

const int match[9] = {2,5,5,4,5,6,3,7,6};
int n, m, a;
string dp[10010];
bool exist[9];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(exist, exist+9, false);
    for (int i = 0; i < m; i++) {
        cin >> a;
        a--;
        exist[a] = true;
    }

    fill(dp, dp+10010, "");
    for (int i = 0; i < n; i++) {
        if (i && dp[i].size() == 0) continue;

        for (int j = 0; j < 10; j++) {
            if (!exist[j]) continue;

            int t = i + match[j];
            string s1 = dp[t];
            string s2 = dp[i] + to_string(j + 1);

            if (s1.size() <= s2.size()) {
                if (s1.size() < s2.size()) {
                    dp[t] = s2;
                } else {
                    int k = 0;
                    bool s2_is_big = false;
                    while (true) {
                        if (s1[k] > s2[k]) {
                            break;
                        } else if (s1[k] < s2[k]) {
                            s2_is_big = true;
                            break;
                        }
                        k++;
                    }

                    if (s2_is_big) {
                        dp[t] = s2;
                    }
                }
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}