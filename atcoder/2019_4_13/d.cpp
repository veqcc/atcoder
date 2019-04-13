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

    int n, k;
    string s;
    cin >> n >> k >> s;

    int l = 0, r = 1; // [l, r)
    int ans = 1;
    int zero = s[0] == '0';

    while (true) {
        if (r == n) break;

        if (zero == k) {
            if (s[r-1] == '1' && s[r] == '0') {
                if (s[l] == '0' && s[l+1] == '1') {
                    zero--;
                }
                l++;
            } else {
                r++;
                ans = max(ans, r - l);
            }
        } else {
            if (s[r-1] == '1' && s[r] == '0') {
                zero++;
            }
            r++;
            ans = max(ans, r - l);
        }
    }

    cout << ans << "\n";
    return 0;
}