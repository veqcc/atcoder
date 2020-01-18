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

    int n, k, s;
    cin >> n >> k >> s;

    if (s == 1) {
        for (int i = 0; i < k; i++) cout << 1 << ' ';
        for (int i = k; i < n; i++) cout << 2 << ' ';
        cout << '\n';
        return 0;
    }

    if (k == 1) {
        cout << s << ' ';
        if (s == 1000000000) {
            for (int i = 1; i < n; i++) cout << 1 << ' ';
        } else {
            for (int i = 1; i < n; i++) cout << s + 1 << ' ';
        }
        cout << '\n';
        return 0;
    }

    if (k == n) {
        for (int i = 0; i < n; i++) cout << s << ' ';
        cout << '\n';
        return 0;
    }

    int cur = 1;
    for (int i = 0; i <= k; i++) {
        cout << cur << ' ';
        cur = s - cur;
    }

    if (s == 1000000000) {
        for (int i = k + 1; i < n; i++) cout << 2 << ' ';
    } else {
        for (int i = k + 1; i < n; i++) cout << s + 1 << ' ';
    }

    return 0;
}