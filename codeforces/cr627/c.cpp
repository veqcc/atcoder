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
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int l = 0, r = s.size() + 1;

        auto dfs = [&](auto dfs, int cur, int m) -> bool {
            for (int i = 1; i <= m; i++) {
                if (cur + i == s.size()) return true;
                if (s[cur + i] == 'R') return dfs(dfs, cur + i, m);
            }
            return false;
        };

        while (r - l > 1) {
            int m = (l + r) / 2;
            if (dfs(dfs, -1, m)) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << endl;
    }

    return 0;
}