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
        int n;
        cin >> n;

        vector <int> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                ans++;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}