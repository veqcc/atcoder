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
const ll MOD = 1000000000;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;

        ll x = 1, y = 1;
        ll cur = 1;
        stack <ll> st;
        st.push(cur);
        for (char c : s) {
            if (c > '1' && c <= '9') {
                ll num = c - '0';
                cur = cur * num % MOD;
                st.push(cur);
            } else if (c == ')') {
                st.pop();
                cur = st.top();
            } else if (c == 'E') {
                x = (x + cur) % MOD;
            } else if (c == 'W') {
                x = (x - cur + MOD) % MOD;
            } else if (c == 'S') {
                y = (y + cur) % MOD;
            } else if (c == 'N') {
                y = (y - cur + MOD) % MOD;
            }
        }

        if (x == 0) x = MOD;
        if (y == 0) y = MOD;

        cout << "Case #" << t << ": " << x << ' ' << y << endl;
    }

    return 0;
}