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

typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector < vector <P> > testimony(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            testimony[i].push_back(P(x - 1, y));
        }
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (ans >= __builtin_popcount(i)) continue;

        bool possible = true;

        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;

            for (P p : testimony[j]) {
                if (((i >> p.first) & 1) != p.second) {
                    possible = false;
                    break;
                }
            }

            if (!possible) break;
        }

        if (!possible) continue;
        ans = __builtin_popcount(i);
    }

    cout << ans << "\n";
    return 0;
}