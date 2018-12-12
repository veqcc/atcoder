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

    ll N;
    cin >> N;
    ll AB[2*N], A[N], B[N], Asum=0, Bsum=0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        AB[i*2] = A[i];
        AB[i*2+1] = B[i];
        Asum += A[i];
        Bsum += B[i];
    }

    ll ans = min(Asum, Bsum);

    sort(AB, AB+2*N);

    bool opt = false;
    for (int i = 0; i < N; i++) {
        if (A[i] < AB[N] && B[i] < AB[N]) {
            opt = true;
            break;
        }
    }

    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += AB[i];
    }

    if (!opt) {
        for (int i = 0; i < N; i++) {
            ll t = tmp;
            if (AB[N] == max(A[i], B[i])) {
                t = t - min(A[i], B[i]) + AB[N+1];
            } else {
                t = t - min(A[i], B[i]) + AB[N];
            }

            ans = min(ans, t);
        }
    } else {
        ans = min(ans, tmp);
    }

    cout << ans << "\n";
    return 0;
}