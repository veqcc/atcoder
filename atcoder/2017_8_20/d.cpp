#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const ll mod=1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N;
    string s[2];
    cin >> N >> s[0] >> s[1];

    ll ans = 0;
    if (s[0][0] == s[1][0]) {
        ans += 3;
    } else {
        ans += 6;
    }

    for (int i = 1; i < N; i++) {
        if (s[0][i-1] == s[1][i-1]) {
            ans *= 2;
        } else {
            if (s[0][i] != s[1][i] && s[0][i-1] != s[0][i]) {
                ans *= 3;
            }
        }
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}