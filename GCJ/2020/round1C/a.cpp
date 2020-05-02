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

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int x, y;
        cin >> x >> y;

        string m;
        cin >> m;

        int ans = -1;
        for (int i = 0; i < m.size(); i++) {
            if (abs(x) + abs(y) <= i) {
                ans = i;
                break;
            }

            if (m[i] == 'N') {
                y++;
            } else if (m[i] == 'S') {
                y--;
            } else if (m[i] == 'E') {
                x++;
            } else if (m[i] == 'W') {
                x--;
            }

            if (abs(x) + abs(y) <= i + 1) {
                ans = i + 1;
                break;
            }
        }

        if (ans == -1) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << endl;
        }
    }

    return 0;
}