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

    int n, m;
    cin >> n >> m;

    vector <int> cnt(n+1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cnt[l]++;
        cnt[r]--;
    }

    int ans = 0;
    if (cnt[0] == m) ans++;
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i-1];
        if (cnt[i] == m) ans++;
    }

    cout << ans << "\n";
    return 0;
}