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

    for (int t = 0; t < T; t++) {
        vector <int> abc(3);
        cin >> abc[0] >> abc[1] >> abc[2];

        sort(abc.begin(), abc.end());

        int a, b, c;
        a = abc[2];
        b = abc[1];
        c = abc[0];

        int ans = 0;

        if (a) {
            ans++;
            a--;
        }

        if (b) {
            ans++;
            b--;
        }

        if (c) {
            ans++;
            c--;
        }

        if (a && b) {
            ans++;
            a--; b--;
        }

        if (b && c) {
            ans++;
            b--; c--;
        }

        if (c && a) {
            ans++;
            c--; a--;
        }

        if (a && b && c) {
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}