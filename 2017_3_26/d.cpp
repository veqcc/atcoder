#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

ll C[51][51];

void comb_table(int N) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1LL;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    ll v[n];
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v, v+n, greater<ll>());

    ll sm = 0LL;
    for (int i = 0; i < a; i++) sm += v[i];
    cout.precision(20);
    cout << fixed << (double)sm / (double)a << "\n";

    int candidate=0, needed=0;
    for (int i = a; i < n; i++) {
        if (v[i] != v[a-1]) break;
        candidate++;
    }
    for (int i = a-1; i >= 0; i--) {
        if (v[i] != v[a-1]) break;
        candidate++;
        needed++;
    }

    comb_table(n);

    if (v[0] != v[a-1]) {
        cout << C[candidate][needed];
    } else {
        ll ans = 0LL;
        for (int i = a; i <= min(b, candidate); i++) {
            ans += C[candidate][i];
        }
        cout << ans;
    }

    return 0;
}