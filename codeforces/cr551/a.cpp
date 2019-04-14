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

    int n, t;
    cin >> n >> t;

    int mn = 1e9;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;

        if (s < t) {
            s += ((t - s) / d + 1) * d;
            if (s == t + d) s = t;
        }

        if (s < mn) {
            mn = s;
            idx = i + 1;
        }
    }

    cout << idx << "\n";
    return 0;
}