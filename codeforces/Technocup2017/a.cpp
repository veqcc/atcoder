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
    ll a, b;
    cin >> a >> b;

    vector<ll> ans;
    auto dfs = [&](auto dfs, ll cur) -> bool {
        if (cur > b) {
            return false;
        } else if (cur == b) {
            ans.push_back(cur);
            return true;
        } else {
            bool ret = false;
            ret |= dfs(dfs, 2 * cur);
            ret |= dfs(dfs, 10 * cur + 1);
            if (ret) ans.push_back(cur);
            return ret;
        }
    };

    if (dfs(dfs, a)) {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}