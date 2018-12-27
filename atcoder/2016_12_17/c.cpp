#include <algorithm>
#include <iostream>
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

    int n, a, c[4];
    cin >> n;
    c[0] = c[1] = c[2] = c[3] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        a--;
        c[a]++;
    }

    int ans = c[3] + c[2] + c[1] / 2;
    c[0] = max(0, c[0] - c[2]);

    if (c[1] % 2 == 1) {
        ans++;
        c[0] = max(0, c[0] - 2);
    }

    ans += c[0] / 4;
    if (c[0] % 4 > 0) ans++;

    cout << ans << "\n";
    return 0;
}