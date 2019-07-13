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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    bool poison[n][n];
    fill(poison[0], poison[n], false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        poison[a][b] = poison[b][a] = true;
    }

    int pre = n / 2;
    int pos = n - pre;

    int pre_bit = 1 << pre;
    int pos_bit = 1 << pos;

    int stable[pre_bit];
    fill(stable, stable + pre_bit, 0);

    for (int i = 0; i < pre_bit; i++) {
        bool independent = true;
        for (int j = 0; j < pre; j++) {
            for (int k = 0; k < j; k++) {
                if ((i & (1 << j)) && (i & (1 << k)) && poison[j][k]) {
                    independent = false;
                }
            }
        }
        if (independent) stable[i] = __builtin_popcount(i);
    }

    for (int i = 0; i < pre_bit; i++) {
        for (int j = 0; j < pre; j++) {
            stable[i | (1 << j)] = max(stable[i | (1 << j)], stable[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < pos_bit; i++) {
        bool independent = true;
        for (int j = 0; j < pos; j++) {
            for (int k = 0; k < j; k++) {
                if ((i & (1 << j)) && (i & (1 << k)) && poison[j + pre][k + pre]) {
                    independent = false;
                }
            }
        }
        if (!independent) continue;

        bool remain[pre];
        fill(remain, remain + pre, true);

        for (int j = 0; j < pos; j++) {
            if (!(i & (1 << j))) continue;

            for (int k = 0; k < pre; k++) {
                if (poison[j + pre][k]) remain[k] = false;
            }
        }

        int tmp = 0;
        for (int j = 0; j < pre; j++) {
            if (remain[j]) tmp ^= (1 << j);
        }

        ans = max(ans, __builtin_popcount(i) + stable[tmp]);
    }

    cout << ans << "\n";
    return 0;
}