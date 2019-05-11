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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, n, sx, sy;
    cin >> h >> w >> n >> sx >> sy;

    string s, t;
    cin >> s >> t;

    int l = 1, r = w;
    bool yoko = false;
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
            if (t[i] == 'L') if (r < w) r++;
            if (t[i] == 'R') if (l > 1) l--;
        }

        if (s[i] == 'L') l++;
        if (s[i] == 'R') r--;

        if (r < l) yoko = true; // 落ちる
    }
    if (sy < l || sy > r) yoko = true;


    l = 1, r = h;
    bool tate = false;
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
            if (t[i] == 'U') if (r < h) r++;
            if (t[i] == 'D') if (l > 1) l--;
        }

        if (s[i] == 'U') l++;
        if (s[i] == 'D') r--;

        if (r < l) tate = true; // 落ちる
    }
    if (sx < l || sx > r) tate = true;


    if (yoko || tate) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}