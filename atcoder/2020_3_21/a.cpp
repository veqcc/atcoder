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
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    vector<vector<int>> cnt(h, vector<int>(w, 1e9));
    cnt[0][0] = s[0][0] == '#' ? 1 : 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i) {
                if (s[i][j] == s[i - 1][j]) {
                    cnt[i][j] = min(cnt[i][j], cnt[i - 1][j]);
                } else {
                    cnt[i][j] = min(cnt[i][j], cnt[i - 1][j] + 1);
                }
            }
            if (j) {
                if (s[i][j] == s[i][j - 1]) {
                    cnt[i][j] = min(cnt[i][j], cnt[i][j - 1]);
                } else {
                    cnt[i][j] = min(cnt[i][j], cnt[i][j - 1] + 1);
                }
            }
        }
    }

    cout << (cnt[h - 1][w - 1] + 1) / 2 << endl;
    return 0;
}