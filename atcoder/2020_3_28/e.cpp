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

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i];
    for (int i = 0; i < c; i++) cin >> r[i];

    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    vector<ll> sum;
    for (int i = 0; i < min(a, x); i++) sum.push_back(p[i]);
    for (int i = 0; i < min(b, y); i++) sum.push_back(q[i]);
    for (int i = 0; i < c; i++) sum.push_back(r[i]);

    sort(sum.begin(), sum.end(), greater<ll>());

    ll ans = 0;
    for (int i = 0; i < x + y; i++) ans += sum[i];

    cout << ans << endl;
    return 0;
}