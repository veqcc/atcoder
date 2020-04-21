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
const int mx = 1e9;

int T, a, b;
bool finish;

bool query(int x, int y) {
    if (finish) return true;
    cout << x << ' ' << y << endl;
    string s;
    cin >> s;
    if (s == "CENTER") {
        finish = true;
        return true;
    } else if (s == "HIT") {
        return true;
    } else {
        return false;
    }
}

void solve() {
    finish = false;
    for (int x = - mx / 2; x <= mx / 2; x += mx / 2) {
        for (int y = - mx / 2; y <= mx / 2; y += mx / 2) {
            if (query(x, y)) {
                int lx, rx, ly, ry;
                {
                    int l = - mx - 1, r = x;
                    while (r - l > 1) {
                        int m = (l + r) / 2;
                        if (query(m, y)) r = m;
                        else l = m;
                    }
                    lx = r;
                }
                {
                    int l = x, r = mx + 1;
                    while (r - l > 1) {
                        int m = (l + r) / 2;
                        if (query(m, y)) l = m;
                        else r = m;
                    }
                    rx = l;
                }
                {
                    int l = - mx - 1, r = y;
                    while (r - l > 1) {
                        int m = (l + r) / 2;
                        if (query(x, m)) r = m;
                        else l = m;
                    }
                    ly = r;
                }
                {
                    int l = y, r = mx + 1;
                    while (r - l > 1) {
                        int m = (l + r) / 2;
                        if (query(x, m)) l = m;
                        else r = m;
                    }
                    ry = l;
                }

                query((lx + rx) / 2, (ly + ry) / 2);
                return;
            }
        }
    }
}

int main() {
    cin >> T >> a >> b;
    for (int t = 1; t <= T; t++) solve();
    return 0;
}