#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    ll len = s.length();
    ll ans = 0LL;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'U') {
            ans += len - i - 1;
            ans += 2 * i;
        } else {
            ans += i;
            ans += 2 * (len - i - 1);
        }
    }

    cout << ans << "\n";
    return 0;
}