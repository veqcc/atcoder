#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int INF = 1 << 30;
const int R = 12 * 60 * 60;

int main() {
    int H, M, S, MS, HM;
    cin >> H >> M >> S >> MS >> HM;

    int h = H * 3600 + M * 60 + S;
    int m = h * 12;
    int s = m * 60;
    MS += (s - m) / R;
    HM += (m - h) / R;

    int mn = INF, mx = 0;
    for (int t = 1; t < 1e8; ++t) {
        h += 1;
        m += 12;
        s += 12 * 60;
        if ((s - m) % R == 0 || (m - h) % R == 0) continue;
        if ((s - m) / R > MS || (m - h) / R > HM) break;

        if ((s - m) / R == MS && (m - h) / R == HM) {
            mn = min(mn, t);
            mx = max(mx, t);
        }
    }

    if (mn == INF) {
        cout << -1 << endl;
    } else {
        cout << mn << " " << mx << endl;
    }
    return 0;
}