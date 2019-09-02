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
const ll MAX = 1LL << 60;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, k;
    cin >> h >> w >> k;

    vector <ll> tate(h, w), yoko(w, h);
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        tate[--r]--;
        yoko[--c]--;
    }

    vector <ll> yoko_sum(w), yoko_cost(w);
    for (int i = 0; i < w; i++) {
        yoko_sum[i] = yoko[i];
        if (i) {
            yoko_sum[i] += yoko_sum[i - 1];
            yoko_cost[i] = yoko_cost[i - 1] + yoko_sum[i - 1];
        }
    }
    vector <ll> rev_yoko_sum(w), rev_yoko_cost(w);
    for (int i = w - 1; i >= 0; i--) {
        rev_yoko_sum[i] = yoko[i];
        if (i < w - 1) {
            rev_yoko_sum[i] += rev_yoko_sum[i + 1];
            rev_yoko_cost[i] = rev_yoko_cost[i + 1] + rev_yoko_sum[i + 1];
        }
    }
    ll y = MAX;
    for (int i = 0; i < w; i++) {
        y = min(y, yoko_cost[i] + rev_yoko_cost[i]);
    }

    vector <ll> tate_sum(h), tate_cost(h);
    for (int i = 0; i < h; i++) {
        tate_sum[i] = tate[i];
        if (i) {
            tate_sum[i] += tate_sum[i - 1];
            tate_cost[i] = tate_cost[i - 1] + tate_sum[i - 1];
        }
    }
    vector <ll> rev_tate_sum(h), rev_tate_cost(h);
    for (int i = h - 1; i >= 0; i--) {
        rev_tate_sum[i] = tate[i];
        if (i < h - 1) {
            rev_tate_sum[i] += rev_tate_sum[i + 1];
            rev_tate_cost[i] = rev_tate_cost[i + 1] + rev_tate_sum[i + 1];
        }
    }
    ll t = MAX;
    for (int i = 0; i < h; i++) {
        t = min(t, tate_cost[i] + rev_tate_cost[i]);
    }

    cout << t + y << "\n";
    return 0;
}