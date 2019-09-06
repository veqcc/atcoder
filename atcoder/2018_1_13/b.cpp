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

    string s;
    cin >> s;

    int ans = 0;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '2') {
            c++;
            ans = max(ans, c);
        } else {
            c--;
            if (c < 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if (c != 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << "\n";
    }

    return 0;
}