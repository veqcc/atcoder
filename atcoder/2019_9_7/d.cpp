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

    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    int count = 0;
    int cur = 'a';
    for (int i = 0; i < n; i ++) {
        if (s[i] == cur) {
            ans++;
        } else {
            count++;
            cur = s[i];
        }
    }

    while (k) {
        if (count <= 1) break;
        if (count == 2) {
            ans += 1;
            break;
        }
        ans += 2;
        count -= 2;
        k--;
    }

    cout << ans << "\n";
    return 0;
}