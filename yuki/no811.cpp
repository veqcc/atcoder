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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int divisor_count(int n) {
    int c = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            c++;
            if (i != n / i) {
                c++;
            }
        }
    }
    return c;
}

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

    int n, k;
    cin >> n >> k;

    map <int, int> n_prime = prime_factor(n);

    int mx = 1;
    int cnt = 0;
    for (int m = 1; m < n; m++) {
        map <int, int> m_prime = prime_factor(m);

        int c = 0;
        for (auto itr = n_prime.begin(); itr != n_prime.end(); itr++) {
            c += min(itr->second, m_prime[itr->first]);
        }

        if (c >= k) {
            int d = divisor_count(m);
            if (d > cnt) {
                mx = m;
                cnt = d;
            }
        }
    }

    cout << mx << "\n";
    return 0;
}