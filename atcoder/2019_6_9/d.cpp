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

bool b[2005][2005];
int l[2005][2005];
int r[2005][2005];
int up[2005][2005];
int down[2005][2005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '.') {
                b[i][j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        int c = -1;
        for (int j = 0; j < w; j++) {
            if (b[i][j]) {
                l[i][j] = c;
            } else {
                c = j;
            }
        }

        c = w;
        for (int j = w-1; j >= 0; j--) {
            if (b[i][j]) {
                r[i][j] = c;
            } else {
                c = j;
            }
        }
    }

    for (int j = 0; j < w; j++) {
        int c = -1;
        for (int i = 0; i < h; i++) {
            if (b[i][j]) {
                up[i][j] = c;
            } else {
                c = i;
            }
        }

        c = h;
        for (int i = h-1; i >= 0; i--) {
            if (b[i][j]) {
                down[i][j] = c;
            } else {
                c = i;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (b[i][j]) {
                int tmp = r[i][j] - l[i][j] - 1;
                tmp += down[i][j] - up[i][j] - 1;
                tmp -= 1;
                ans = max(ans, tmp);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}