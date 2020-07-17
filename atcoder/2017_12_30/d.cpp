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

vector<bool> sieve(int n) {
    vector <bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

int main() {
    int q;
    cin >> q;

    int n = 100005;
    auto is_prime = sieve(n);
    vector<int> count(n);
    for (int i = 1; i <= n; i++) {
        count[i] = is_prime[i] && is_prime[(i + 1) / 2];
        count[i] += count[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << count[r] - count[l - 1] << endl;
    }

    return 0;
}