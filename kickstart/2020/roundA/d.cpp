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
        int n, k;
        cin >> n >> k;

        vector <string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        sort(s.begin(), s.end());

        vector <char> cur(2000005);
        for (int j = 0; j < s[0].size(); j++) {
            cur[j] = s[0][j];
        }

        vector <int> len(2000005, 1);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == cur[j]) {
                    len[j]++;
                    if (len[j] == k) {
                        ans++;
                        cur[j] = '?';
                        len[j] = 0;
                    }
                } else {
                    for (int l = j; l < 2000005; l++) {
                        if (l < s[i].size()) {
                            cur[l] = s[i][l];
                        } else {
                            cur[l] = '?';
                        }
                        len[l] = 1;
                    }
                    break;
                }
            }
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}