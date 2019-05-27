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
    cin >> n >> k;

    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ret = 0;
    for (int l = 0; l <= n; l++) {
        for (int r = 0; r <= n; r++) {
            // 左からl個、右からr個取る
            if (l + r > n || l + r > k) continue;

            vector <int> vec;
            for (int i = 0; i < l; i++) vec.push_back(v[i]);
            for (int i = 0; i < r; i++) vec.push_back(v[n - 1 - i]);

            sort(vec.begin(), vec.end(), greater<int>());

            int ans = 0;
            int x = k - l - r; // 捨てられる数
            for (int i = 0; i < l + r; i++) {
                if (i >= l + r - x && vec[i] <= 0) break;
                ans += vec[i];
            }

            ret = max(ret, ans);
        }
    }

    cout << ret << "\n";
    return 0;
}