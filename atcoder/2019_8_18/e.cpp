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

    string s, t;
    cin >> s >> t;

    int n = s.size();
    vector <vector<int>> next(n, vector<int>(26, -1));
    // next[i][j] : 文字jは、i番目以降でどこにでてくるか

    for (int j = 0; j < 26; j++) {
        int prev = -1;
        for (int i = 2 * n - 1; i >= 0; i--) {
            next[i % n][j] = prev;
            if (s[i % n] == 'a' + j) prev = i % n;
        }
    }

    int cur = next[n - 1][t[0] - 'a'];
    if (cur == -1) {
        cout << -1 << '\n';
        return 0;
    }

    ll ans = cur + 1;
    for (int i = 1; i < t.size(); i++) {
        int next_index = next[cur][t[i] - 'a'];
        if (next_index == -1) {
            cout << -1 << '\n';
            return 0;
        }

        if (next_index == cur) {
            ans += n;
        } else {
            ans += (next_index - cur + n) % n;
            cur = next_index;
        }
    }

    cout << ans << "\n";
    return 0;
}