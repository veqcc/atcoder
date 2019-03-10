#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll A, B;
    cin >> A >> B;
    A--;

    ll ans = 0LL;
    for (int i = 1; i < 50; i++) {
        // i-1 bit目が立っているものがいくつあるか
        ll b = 1LL << i;
        ll c = 1LL << (i - 1);
        ll cnt = 0;
        cnt += B / b * c + max(0LL, B % b - c + 1);
        cnt -= A / b * c + max(0LL, A % b - c + 1);
        if (cnt % 2 == 1) ans += c;
    }

    cout << ans << "\n";
    return 0;
}