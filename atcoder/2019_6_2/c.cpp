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

    ll n, x;
    cin >> n >> x;

    ll b[n], l[n], u[n];
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> l[i] >> u[i];
        sm += b[i] * l[i];
    }

    vector <ll> benefit(n);
    for (int i = 0; i < n; i++) benefit[i] = b[i] * l[i] + (x - b[i]) * u[i];

    sort(benefit.begin(), benefit.end(), greater<ll>());

    vector <ll> sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + benefit[i];
    }

    ll mn = -1, mx = n * x;
    while (mx > mn + 1) {
        ll k = (mx + mn) / 2; // k点で満たすか
        ll p = k / x;
        ll q = k % x;

        bool possible = false;
        for (int i = 0; i < n; i++) {
            ll tmp = 0;
            if (q <= b[i]) {
                tmp += q * l[i];
            } else {
                tmp += b[i] * l[i] + (q - b[i]) * u[i];
            }

            tmp += sum[p];
            ll t = b[i] * l[i] + (x - b[i]) * u[i];
            if (p > 0 && t >= benefit[p-1]) {
                tmp = tmp + benefit[p] - t;
            }

            if (tmp >= sm) {
                possible = true;
                break;
            }
        }

        if (possible) {
            mx = k;
        } else {
            mn = k;
        }
    }

    cout << mx << "\n";
    return 0;
}