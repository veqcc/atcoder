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

// 約数のvectorを返す
vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    vector<bool> divisible(1000005, false);
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i - 1] == a[i]) {
            divisible[a[i]] = true;
            continue;
        }
        if (i < n - 1 && a[i + 1] == a[i]) {
            divisible[a[i]] = true;
            continue;
        }

        auto div = divisor(a[i]);
        bool ok = true;
        for (auto x : div) {
            if (divisible[x]) {
                ok = false;
                break;
            }
        }

        if (ok) ans++;
        divisible[a[i]] = true;
    }

    cout << ans << endl;
    return 0;
}