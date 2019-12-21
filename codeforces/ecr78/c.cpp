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
        int n;
        cin >> n;
        vector <int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];

        // 左を見て、イチゴジャムがいくつ多いかの、一番右に近い場所
        vector <int> left(2 * n + 1, n + 100005);
        int cur = n;
        left[cur] = n;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cur++;
            } else {
                cur--;
            }
            left[cur] = n - i - 1;
        }

        int ans = 2 * n;
        int right = n;
        ans = min(ans, left[2 * n - right] + n);
        for (int i = 2 * n - 1; i >= n; i--) {
            if (a[i] == 1) {
                right++;
            } else {
                right--;
            }
            ans = min(ans, left[2 * n - right] + (i - n));
        }

        cout << ans << '\n';
    }

    return 0;
}