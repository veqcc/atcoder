#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
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

    int n, m;
    cin >> n >> m;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector <int> edges[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
    }

    map <int, bool> mp;
    mp[p[n-1]] = true;
    int sz = 1;
    int ans = 0;
    for (int i = n-2; i >= 0; i--) {
        int cnt = 0;
        for (int x : edges[p[i]]) {
            if (mp[x]) cnt++;
        }

        if (cnt == sz) {
            ans++;
        } else {
            mp[p[i]] = true;
            sz++;
        }
    }

    cout << ans << "\n";
    return 0;
}