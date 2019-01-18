#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    ll ans = 0LL;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            ll t = 0LL;

            for (int k = i; k <= j; k++) {
                t *= 10;
                t += (ll)(s[k] - '0');
            }

            int left = max(0, i-1);
            int right = max(0, (int)s.size() - j - 2);
            ans += t * (1LL << left) * (1LL << right);
        }
    }


    cout << ans << "\n";
    return 0;
}