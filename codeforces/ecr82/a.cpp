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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int zero = 0;
        bool one = false;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                if (one) {
                    zero++;
                }
            } else {
                one = true;
                ans += zero;
                zero = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}