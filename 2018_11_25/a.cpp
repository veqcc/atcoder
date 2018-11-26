#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int t, a, b, c, d;
    cin >> t >> a >> b >> c >> d;

    int ans = 0;
    if (t >= c) {
        ans += d;
        t -= c;
    }
    if (t >= a) {
        ans += b;
    }

    cout << ans << endl;
    return 0;
}