#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    bool red[n];
    int cnt[n];
    fill(red, red+n, false);
    fill(cnt, cnt+n, 1);
    red[0] = true;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        cnt[x]--; cnt[y]++;
        if (red[x]) red[y] = true;
        if (cnt[x] == 0) red[x] = false;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (red[i]) ans++;
    }

    cout << ans << "\n";
    return 0;
}