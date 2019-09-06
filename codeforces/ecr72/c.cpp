#include <functional>
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
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.size();

        int ans = 0;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zero++;
                continue;
            }

            for (int j = 1; ; j++) {
                int len = (int)log2(j) + 1;
                if (j > zero + len) break;
                if (i + len - 1 >= n) break;

                int ok = 1;
                int val = j;
                for (int k = i + len - 1; k >= i; k--) {
                    if ((int)(s[k] - '0') != (val & 1)) {
                        ok = 0;
                        break;
                    }

                    val >>= 1;
                }

                ans += ok;
            }

            zero = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}