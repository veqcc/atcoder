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

    string t;
    cin >> t;

    int ans = 0;
    for (int k = 0; k < 2; k++) {
        int cur = 0;
        for (int i = 0; i < t.size(); i++) {
            if ((i + k) % 2 == 0) {
                if (t[i] == '2' || t[i] == '?') {
                    cur++;
                    ans = max(ans, cur);
                } else {
                    cur = 0;
                }
            } else {
                if (t[i] == '5' || t[i] == '?') {
                    if (cur) cur++;
                    ans = max(ans, cur);
                } else {
                    cur = 0;
                }
            }
        }
    }

    cout << ans / 2 * 2 << "\n";
    return 0;
}