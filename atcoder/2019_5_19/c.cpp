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

    double n, k;
    cin >> n >> k;

    double ans = 0.0;
    for (double i = 1; i <= n; i++) {
        double cnt = 0.0;
        double now = i;
        while (now < k) {
            now *= 2.0;
            cnt += 1.0;
        }
        ans += 1.0 / pow(2.0, cnt);
    }

    cout << fixed << setprecision(12) << ans / n << "\n";
    return 0;
}