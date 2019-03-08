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
    int l = 0, r = 0;
    while (l < n && r < n) {
        if (a[r] - a[l] <= 5) {
            ans = max(ans, r - l + 1);
            r++;
        } else {
            l++;
        }
    }

    cout << ans << "\n";
    return 0;
}