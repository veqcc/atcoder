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

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (m % n != 0) {
        cout << -1 << '\n';
        return 0;
    }

    n = m / n;
    auto mp = prime_factor(n);

    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->first == 2 || itr->first == 3) {
            ans += itr->second;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << "\n";
    return 0;
}