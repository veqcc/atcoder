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
    string s;
    cin >> s;

    int ans = 0, cur = 0;
    for (auto c : s) {
        if (c == 'R') {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 0;
        }
    }

    cout << ans << endl;
    return 0;
}