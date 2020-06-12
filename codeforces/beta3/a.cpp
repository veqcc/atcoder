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
    string s, t;
    cin >> s >> t;
    int x = s[0] - t[0];
    int y = s[1] - t[1];
    vector<string> ans(max(abs(x), abs(y)));
    for (int i = 0; i < abs(x); i++) {
        if (x > 0) ans[i] += 'L';
        else ans[i] += 'R';
    }
    for (int i = 0; i < abs(y); i++) {
        if (y > 0) ans[i] += 'D';
        else ans[i] += 'U';
    }
    cout << ans.size() << endl;
    for (auto s : ans) cout << s << endl;
    return 0;
}