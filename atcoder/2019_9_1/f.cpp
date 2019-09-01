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
typedef long double ld;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <ld> x(n), y(n);
    vector <P> angle(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        angle[i] = {atan2(y[i], x[i]), i};
    }

    sort(angle.begin(), angle.end());

    ld ans = 0.0;
    for (int i = 0; i < n; i++) {
        ld curX = 0.0, curY = 0.0;
        for (int j = i; j < i + n; j++) {
            curX += x[angle[j % n].second];
            curY += y[angle[j % n].second];
            ans = max(ans, sqrtl(curX * curX + curY * curY));
        }
    }

    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}