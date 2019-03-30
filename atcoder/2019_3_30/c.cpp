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

int n, q;
string s;
char t[200005], d[200005];

bool check(int k, int ok, int ng) {
    // k番目のゴーレムが消滅するか
    int cur = k;
    for (int i = 0; i < q; i++) {
        if (k == ok) return true;
        if (k == ng) return false;
        if (t[i] == s[k]) {
            if (d[i] == 'L') {
                k--;
            } else {
                k++;
            }
        }
    }

    if (k == ok) return true;
    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;

    for (int i = 0; i < q; i++) {
        cin >> t[i] >> d[i];
    }

    int ans = n;

    // 二分探索
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, -1, n)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    ans -= (l + 1);

    l = -1, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, n, -1)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    ans -= (n - r);

    cout << ans << "\n";
    return 0;
}