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
typedef pair <ll, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int X, Y, a, b, c;
    cin >> X >> Y >> a >> b >> c;

    vector <ll> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i];
    for (int i = 0; i < c; i++) cin >> r[i];

    priority_queue <P> Q;
    for (int i = 0; i < a; i++) Q.push({p[i], 0});
    for (int i = 0; i < b; i++) Q.push({q[i], 1});
    for (int i = 0; i < c; i++) Q.push({r[i], 2});

    int x = 0, y = 0, total = 0;
    ll ans = 0;

    while (total < X + Y) {
        P elm = Q.top();
        Q.pop();

        int val = elm.first;
        int idx = elm.second;

        if (idx == 0) {
            if (x < X && total < X + Y) {
                ans += val;
                x++;
                total++;
            }
        } else if (idx == 1) {
            if (y < Y && total < X + Y) {
                ans += val;
                y++;
                total++;
            }
        } else {
            if (total < X + Y) {
                ans += val;
                total++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}