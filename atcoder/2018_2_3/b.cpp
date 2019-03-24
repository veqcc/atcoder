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

    int n;
    cin >> n;

    ll a[n], b[n], asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        asum += a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bsum += b[i];
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > a[i]) {
            cnt += (b[i] - a[i] + 1) / 2;
        }
    }

    if (cnt <= bsum - asum) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}