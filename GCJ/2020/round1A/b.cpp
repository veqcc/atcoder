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
        int n;
        cin >> n;

        cout << "Case #" << t << ": \n";

        if (n <= 500) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ' << 1 << '\n';
            }
        } else {
            vector <bool> on(32, false);
            n -= 32;
            for (int i = 31; i >= 0; i--) {
                if (n > pow(2, i)) {
                    on[i] = true;
                    n -= pow(2, i);
                }
            }

            bool left = true;
            for (int i = 1; i <= 32; i++) {
                if (on[i - 1]) {
                    if (left) {
                        for (int j = 1; j <= i; j++) cout << i << ' ' << j << '\n';
                        left = false;
                    } else {
                        for (int j = i; j; j--) cout << i << ' ' << j << '\n';
                        left = true;
                    }
                    n++;
                } else {
                    cout << i << ' ' << (left ? 1 : i) << '\n';
                }
            }

            for (int i = 0; i < n; i++) {
                cout << i + 33 << ' ' << (left ? 1 : i + 33) << '\n';
            }
        }
    }

    return 0;
}