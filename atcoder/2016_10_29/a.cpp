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
    string s, t;
    cin >> n >> s >> t;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        // i文字一致する

        bool same = true;
        for (int j = 0; j < i; j++) {
            if (s[n-i+j] != t[j]) {
                same = false;
            }
        }

        if (same) {
            ans = i;
        }
    }

    cout << 2 * n - ans << "\n";
    return 0;
}