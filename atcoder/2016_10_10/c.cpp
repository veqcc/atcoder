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
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int W, H;
    cin >> W >> H;
    ll P[W], Q[H];
    for (int i = 0; i < W; i++) cin >> P[i];
    for (int i = 0; i < H; i++) cin >> Q[i];

    sort(P, P+W);
    sort(Q, Q+H);

    int p = 0, q = 0;
    ll ans = 0LL;
    for (int i = 0; i < W + H; i++) {
        if (q == H || (p < W && P[p] < Q[q])) {
            ans += P[p] * (H + 1 - q);
            p++;
        } else {
            ans += Q[q] * (W + 1 - p);
            q++;
        }
    }

    cout << ans << "\n";
    return 0;
}