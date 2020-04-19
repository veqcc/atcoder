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

    for (int t = 1; t <= T; t++) {
        int n, b;
        cin >> n >> b;

        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int sum = 0;
        int ans = 0;
        for (; ans < n; ans++) {
            if (sum + a[ans] <= b) {
                sum += a[ans];
            } else {
                break;
            }
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}