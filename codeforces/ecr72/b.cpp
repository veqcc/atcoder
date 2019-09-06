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

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, x;
        cin >> n >> x;

        int last = 0;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            int d, h;
            cin >> d >> h;
            last = max(last, d);
            mx = max(mx, d - h);
        }

        if (x <= last) {
            cout << 1 << '\n';
            continue;
        }

        if (mx <= 0) {
            cout << -1 << '\n';
            continue;
        }

        cout << 1 + (x - last + mx - 1) / mx << '\n';
    }

    return 0;
}