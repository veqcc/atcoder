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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto possible = [&](int len) -> bool {
        ll count = 0;
        for (int i = 0; i < n; i++) {
            count += (a[i] - 1) / len;
        }
        return count <= k;
    };

    int l = 0, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (possible(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
    return 0;
}