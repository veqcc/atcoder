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

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;

        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '<') {
                tmp++;
            } else {
                break;
            }
        }

        int ans = tmp;

        tmp = 0;
        for (int j = n-1; j >= 0; j--) {
            if (s[j] == '>') {
                tmp++;
            } else {
                break;
            }
        }

        ans = min(ans, tmp);
        cout << ans << "\n";
    }

    return 0;
}