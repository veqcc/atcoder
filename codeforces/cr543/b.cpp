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

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            mp[a[i]+a[j]]++;
        }
    }

    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        ans = max(ans, itr->second);
    }

    cout << ans << "\n";
    return 0;
}