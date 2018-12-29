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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    int X, Y;
    cin >> s >> X >> Y;
    int pos = 0, len = s.length();
    vector<int> vx, vy;
    bool is_x = true;
    while (pos < len) {
        if (is_x) {
            if (s[pos] == 'T') {
                is_x = false;
                pos++;
            } else {
                int l = 0;
                while (pos < len && s[pos] == 'F') {
                    l++;
                    pos++;
                }
                vx.push_back(l);
            }
        } else {
            if (s[pos] == 'T') {
                is_x = true;
                pos++;
            }
            else {
                int l = 0;
                while (pos < len && s[pos] == 'F') {
                    l++;
                    pos++;
                }
                vy.push_back(l);
            }
        }
    }

    bool dpx[2*len+1], dpy[2*len+1], tmp[2*len+1];
    fill(dpx, dpx+2*len+1, false);

    dpx[len] = true;
    for (int i = 0; i < vx.size(); i++) {
        fill(tmp, tmp+2*len+1, false);
        for (int j = 0; j <= 2*len; j++) {
            if (dpx[j]) {
                tmp[j+vx[i]] = true;
                if (s[0] == 'T' || i != 0) tmp[j-vx[i]] = true;
            }
        }

        for (int j = 0; j <= 2*len; j++) {
            dpx[j] = tmp[j];
        }
    }

    fill(dpy, dpy+2*len+1, false);
    dpy[len] = true;
    for (int i = 0; i < vy.size(); i++) {
        fill(tmp, tmp+2*len+1, false);
        for (int j = 0; j <= 2*len; j++) {
            if (dpy[j]) {
                tmp[j+vy[i]] = true;
                tmp[j-vy[i]] = true;
            }
        }

        for (int j = 0; j <= 2*len; j++) {
            dpy[j] = tmp[j];
        }
    }

    if (dpx[len+X] && dpy[len+Y]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}