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

    int ans = 0;
    for (int j = 1; j < n-1; j++) {
        for (int i = j-1; i >= 0; i--) {
            int k = 2 * j - i;
            if (k >= n) break;

            if (s[i] == 'U' && s[j] == 'M' && s[k] == 'G') ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}