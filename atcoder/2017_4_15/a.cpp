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

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int ans = 1;
    int state = 1; // 0:up, 1:any, 2:down
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            if (state == 2) {
                ans++;
                state = 1;
            } else {
                state = 0;
            }
        } else if (a[i] < a[i-1]) {
            if (state == 0) {
                ans++;
                state = 1;
            } else {
                state = 2;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}