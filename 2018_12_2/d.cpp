#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int w[101];
    fill(w, w+101, 0);
    for (int i = 2; i <= n; i++) {
        int j = 2;
        int t = i;
        while (t > 1) {
            if (t % j == 0) {
                w[j]++;
                t = t / j;
            } else {
                j++;
            }
        }
    }

    int c2=0, c4=0, c14=0, c24=0, c74=0;
    for (int i = 2; i < 101; i++) {
        if (w[i] >= 74) c74++;
        if (w[i] >= 24) c24++;
        if (w[i] >= 14) c14++;
        if (w[i] >= 4)  c4++;
        if (w[i] >= 2)  c2++;
    }

    int ans = 0;
    ans += c74;
    ans += c24 * (c2-1);
    ans += c14 * (c4-1);
    ans += c4 * (c4-1) * (c2-2) / 2;

    cout << ans;
    return 0;
}