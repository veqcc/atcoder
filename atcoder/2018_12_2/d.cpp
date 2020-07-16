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
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        auto f = prime_factor(i);
        for (int i = 1; i <= n; i++) mp[i] += f[i];
    }

    map<int, int> count;
    for (int i = 1; i <= n; i++) count[mp[i]]++;
    for (int i = n; i; i--) count[i - 1] += count[i];

    int ans = 0;
    ans += count[74];
    ans += count[24] * (count[2] - 1);
    ans += count[14] * (count[4] - 1);
    ans += count[4] * (count[4] - 1) / 2 * (count[2] - 2);

    cout << ans << endl;
    return 0;
}