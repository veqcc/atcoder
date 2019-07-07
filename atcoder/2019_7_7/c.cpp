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
const int MOD = 2019;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin >> l >> r;

    if (r - l >= 2019) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 2019;
    for (int i = l; i < r; i++) {
        for (int j = i+1; j <= r; j++) {
            int tmp = (i % MOD) * (j % MOD) % MOD;
            ans = min(tmp, ans);
        }
    }

    cout << ans << "\n";
    return 0;
}