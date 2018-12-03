#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

ll N;
int d[3] = {3, 5, 7};

ll dfs(ll x) {
    if (x > N) return 0;

    ll ret=0LL;
    int c3=0, c5=0, c7=0;
    ll t=x;
    while (t > 0) {
        ll tmp = t % 10;
        if (tmp == 3LL) c3++;
        if (tmp == 5LL) c5++;
        if (tmp == 7LL) c7++;
        t /= 10;
    }

    if (c3 * c5 * c7 > 0) ret++;

    for (int i = 0; i < 3; i++) {
        ret += dfs(x*10+d[i]);
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    cout << dfs(0) << "\n";
    return 0;
}