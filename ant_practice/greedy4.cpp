#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=20000;

ll N, L[MAX_N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    ll ans = 0;

    while (N > 1LL) {
        int mi1 = 0;
        int mi2 = 1;
        if (L[mi1] > L[mi2]) swap(mi1, mi2);

        for (int i = 2; i < N; i++) {
            if (L[i] < L[mi1]) {
                mi2 = mi1;
                mi1 = i;
            } else if (L[i] < L[mi2]) {
                mi2 = i;
            }
        }

        ll t = L[mi1] + L[mi2];
        ans += t;

        if (mi1 == N-1) swap(mi1, mi2);

        L[mi1] = t;
        L[mi2] = L[N-1];
        N--;
    }

    cout << ans << "\n";
    return 0;
}