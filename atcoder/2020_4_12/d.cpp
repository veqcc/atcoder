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

    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        vector <int> left(3), right(3), same(3);
        for (int j = 0; j < i; j++) {
            if (s[j] == 'R') left[0]++;
            if (s[j] == 'G') left[1]++;
            if (s[j] == 'B') left[2]++;
        }
        for (int j = i + 1; j < n; j++) {
            if (s[j] == 'R') right[0]++;
            if (s[j] == 'G') right[1]++;
            if (s[j] == 'B') right[2]++;
        }

        if (s[i] == 'R') {
            ans += left[1] * right[2];
            ans += left[2] * right[1];
        } else if (s[i] == 'G') {
            ans += left[0] * right[2];
            ans += left[2] * right[0];
        } else {
            ans += left[1] * right[0];
            ans += left[0] * right[1];
        }

        for (int j = 1; i - j >= 0 && i + j < n; j++) {
            if (s[i - j] != s[i] && s[i] != s[i + j] && s[i + j] != s[i - j]) {
                ans--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}