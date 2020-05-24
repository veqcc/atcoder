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
typedef pair <ll, ll> P;

int main() {
    int T;
    cin >> T;

    while (T--) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, n});

        map<ll, bool> mp;
        ll ans = 1e18;
        while (true) {
            P p = q.top();
            q.pop();

            ll cost = p.first;
            ll cur = p.second;

            if (mp[cur]) continue;
            mp[cur] = true;

            if (cost >= ans) break;

            if (cur == 1) {
                ans = min(ans, cost + d);
            }

            if (cur < (1e18 - cost) / d) {
                ans = min(ans, cost + cur * d);
            }

            if (cur % 2 == 1) {
                q.push({cost + a + d, (cur + 1) / 2});
                q.push({cost + a + d, (cur - 1) / 2});
            } else {
                q.push({cost + a, cur / 2});
            }

            if (cur % 3 == 1) {
                q.push({cost + b + 2 * d, (cur + 2) / 3});
                q.push({cost + b + d, (cur - 1) / 3});
            } else if (cur % 3 == 2) {
                q.push({cost + b + 2 * d, (cur - 2) / 3});
                q.push({cost + b + d, (cur + 1) / 3});
            } else {
                q.push({cost + b, cur / 3});
            }

            for (int i = 1; i < 5; i++) {
                if (cur % 5 == i) {
                    q.push({cost + c + (5 - i) * d, (cur + 5 - i) / 5});
                    q.push({cost + c + i * d, (cur - i) / 5});
                }
            }
            if (cur % 5 == 0) {
                q.push({cost + c, cur / 5});
            }
        }

        cout << ans << endl;
    }

    return 0;
}