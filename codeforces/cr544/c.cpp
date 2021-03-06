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

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 最小の戦闘力の人がa[i]の時
        int idx = lower_bound(a.begin(), a.end(), a[i] + 6) - a.begin();
        ans = max(ans, idx - i);
    }

    cout << ans << "\n";
    return 0;
}