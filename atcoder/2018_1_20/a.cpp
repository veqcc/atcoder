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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    string s;
    cin >> n >> s;

    bool all_a = true;
    int cur = 0;

    ll init = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            cur++;
            init += cur;
        } else {
            cur = 0;
            all_a = false;
        }
    }

    if (all_a) {
        ll mx = s.size() * n;
        cout << mx * (mx + 1) / 2 << '\n';
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            cur++;
            ans += cur;
        } else {
            cur = 0;
        }
    }

    ans *= n - 1;

    cout << init + ans << "\n";
    return 0;
}