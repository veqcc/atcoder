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

    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    vector <ll> th(10);
    ll ten = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a = a / 1000 + 1;
        ten += a / 10;
        a %= 10;
        th[a]++;
    }

    bool yes = true;

    if (ten <= z) {
        z -= ten;
    } else {
        ten -= z;
        z = 0;
        if (ten * 2 <= y) {
            y -= ten * 2;
        } else {
            ten -= y / 2;
            y %= 2;
            if (ten * 10 <= x) {
                x -= ten * 10;
            } else {
                yes = false;
            }
        };
    }

    for (int i = 9; i; i--) {
        if (th[i] <= z) {
            z -= th[i];
        } else {
            th[i] -= z;
            z = 0;
            if (th[i] <= y) {
                y -= th[i];
                if (i >= 5) th[i - 5] += th[i];
            } else {
                th[i] -= y;
                if (i >= 5) th[i - 5] += y;
                y = 0;
                if (th[i] * i <= x) {
                    x -= th[i] * i;
                } else {
                    yes = false;
                }
            }
        }
    }

    cout << (yes ? "Yes" : "No") << endl;
    return 0;
}