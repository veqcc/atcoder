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

    vector <bool> is_ascent(n);
    vector <int> mn(n), mx(n);
    int ascent_count = 0;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;

        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;

            if (j == 0) {
                mn[i] = x;
                mx[i] = x;
            } else {
                if (x > mn[i]) is_ascent[i] = true;
                mn[i] = min(mn[i], x);
                mx[i] = max(mx[i], x);
            }
        }

        if (is_ascent[i]) {
            ascent_count++;
        }
    }

    ll ans = 0;
    ans += (ll)ascent_count * (ll)ascent_count;
    ans += (ll)ascent_count * (ll)(n - ascent_count) * 2LL;

    vector <int> remain;
    for (int i = 0; i < n; i++) {
        if (!is_ascent[i]) {
            remain.push_back(mx[i]);
        }
    }

    sort(remain.begin(), remain.end());

    int remain_size = remain.size();
    for (int i = 0; i < n; i++) {
        if (!is_ascent[i]) {
            int idx = upper_bound(remain.begin(), remain.end(), mn[i]) - remain.begin();
            ans += remain_size - idx;
        }
    }

    cout << ans << "\n";
    return 0;
}