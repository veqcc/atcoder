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

bool ok(char i, char j, char k, string s) {
    for (int n = 0; n < s.size(); n++) {
        if (s[n] == i) {
            if (j == 'a') return true;

            return ok(j, k, 'a', s.substr(n + 1, s.size() - n - 1));
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (char i = '0'; i <= '9'; i++) {
        for (char j = '0'; j <= '9'; j++) {
            for (char k = '0'; k <= '9'; k++) {
                if (ok(i, j, k, s)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}