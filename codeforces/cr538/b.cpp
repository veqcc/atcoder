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
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], sa[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa[i] = a[i];
    }

    sort(sa, sa+n, greater<int>());

    map <int, int> mp;
    ll ans = 0LL;
    for (int i = 0; i < m * k; i++) {
        mp[sa[i]]++;
        ans += (ll)sa[i];
    }
    cout << ans << "\n";

    vector <int> ret;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] > 0) {
            mp[a[i]]--;
            ret.push_back(i);
        }
    }

    for (int i = m; i < ret.size(); i += m) {
        cout << ret[i] << " ";
    }

    cout << "\n";
    return 0;
}