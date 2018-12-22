#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int c = 0;
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W') {
            ans += (ll)(i - c);
            cout << i - c << endl;
            c++;
        }
    }

    cout << ans;
    return 0;
}