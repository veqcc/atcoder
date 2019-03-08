#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
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

    int n, K;
    cin >> n >> K;

    int a[n];
    ll b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll ret = 0;
    for (int i = 0; i < 30; i++) {
        int k = 0;
        if (i) {
            if (!(K & 1 << i)) continue;
            for (int j = i + 1; j < 30; j++) if (K & (1 << j)) k += (1 << j);
            for (int j = 0; j < i; j++) k += (1 << j);
        } else {
            k = K;
        }

        ll ans = 0;
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int l = 0; l < 30; l++) {
                if ((a[j] & 1 << l) && !(k & 1 << l)) flag = false;
            }
            if (flag) ans += b[j];
        }

        ret = max(ret, ans);
    }

    cout << ret << '\n';
    return 0;
}