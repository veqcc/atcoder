#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> cnt(n+1, 0);
    int l[q], r[q];
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j++) cnt[j]++;
    }

    int sm = 0;
    vector <int> one(n+1, 0), two(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) one[i]++;
        one[i] += one[i-1];

        if (cnt[i] == 2) two[i]++;
        two[i] += two[i-1];

        if (cnt[i] > 0) sm++;
    }

    int mx = 0;
    for (int i = 0; i < q; i++) {
        for (int j = i+1; j < q; j++) {
            int ret = sm;
            ret -= (one[r[i]] - one[l[i] - 1]);
            ret -= (one[r[j]] - one[l[j] - 1]);

            int left = max(l[i], l[j]);
            int right = min(r[i], r[j]);
            if (right >= left) ret -= (two[right] - two[left - 1]);

            mx = max(mx, ret);
        }
    }

    cout << mx << "\n";
    return 0;
}