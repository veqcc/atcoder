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

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<ll> primes, candidates;
    ll cur = 100001;
    while (primes.size() < 10) {
        if (is_prime(cur)) {
            for (ll x : primes) {
                candidates.push_back(x * cur);
            }
            candidates.push_back(cur * cur);
            primes.push_back(cur);
        }
        cur++;
    }

    sort(candidates.begin(), candidates.end());

    cout << candidates[n - 2] << endl;
    return 0;
}