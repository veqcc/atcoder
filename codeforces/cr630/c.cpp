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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<vector<int>> cnt((k + 1) / 2, vector<int>(26));
        for (int i = 0; i < n; i++) {
            int idx = min(i % k, k - i % k - 1);
            cnt[idx][s[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < (k + 1) / 2; i++) {
            int mx = 0, sm = 0;
            for (int j = 0; j < 26; j++) {
                mx = max(mx, cnt[i][j]);
                sm += cnt[i][j];
            }
            ans += sm - mx;
        }

        cout << ans << '\n';
    }

    return 0;
}