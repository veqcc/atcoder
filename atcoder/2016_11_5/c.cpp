#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <cstring>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll K;
    cin >> N >> K;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[gcd(K, a)]++;
    }

    ll ans = 0;
    for (auto p:mp) {
        for (auto q:mp) {
            if (p.first * q.first % K == 0) {
                if (p == q) {
                    ans += p.second * (p.second - 1);
                } else {
                    ans += p.second * q.second;
                }
            }
        }
    }

    cout << ans / 2 << "\n";
    return 0;
}