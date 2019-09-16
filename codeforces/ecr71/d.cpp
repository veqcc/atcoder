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
const ll MOD = 998244353LL;
typedef pair <int, int> P;

bool sortbysec(const P &a, const P &b) {
    return (a.second < b.second);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }

    vector <P> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());
    if (vec[0].first == vec[n - 1].first) {
        cout << 0 << "\n";
        return 0;
    }

    bool same = true;
    for (int i = 1; i < n ; i++) {
        if (vec[i - 1].second > vec[i].second) same = false;
    }

    ll tmp = 1;
    ll count = 1;
    ll fact = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i].first == vec[i - 1].first) {
            count++;
            fact = fact * count % MOD;
        } else {
            tmp = tmp * fact % MOD;
            count = 1;
            fact = 1;
        }
    }
    tmp = tmp * fact % MOD;
    ans = (ans - tmp + MOD) % MOD;

    if (same) {
        tmp = 1;
        count = 1;
        fact = 1;
        for (int i = 1; i < n; i++) {
            if (vec[i].first == vec[i - 1].first) {
                if (vec[i].second == vec[i - 1].second) {
                    count++;
                    fact = fact * count % MOD;
                    continue;
                }
            }
            tmp = tmp * fact % MOD;
            count = 1;
            fact = 1;
        }
        tmp = tmp * fact % MOD;
        ans = (ans + tmp) % MOD;
    }

    sort(vec.begin(), vec.end(), sortbysec);
    if (vec[0].second == vec[n - 1].second) {
        cout << 0 << "\n";
        return 0;
    }

    tmp = 1;
    count = 1;
    fact = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i].second == vec[i - 1].second) {
            count++;
            fact = fact * count % MOD;
        } else {
            tmp = tmp * fact % MOD;
            count = 1;
            fact = 1;
        }
    }
    tmp = tmp * fact % MOD;
    ans = (ans - tmp + MOD) % MOD;

    cout << ans << "\n";
    return 0;
}