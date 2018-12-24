#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const ll inf = 1LL << 50;

int main() {
    int N, M;
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c[i] = -c[i];
    }

    ll dist[NMAX];
    fill(dist, dist+NMAX, inf);

    dist[0] = 0;

    for (int loop = 0; loop < N - 1; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == inf) continue;
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
            }
        }
    }

    ll ans = dist[N - 1];

    bool negative[NMAX];
    fill(negative, negative+NMAX, false);

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == inf) continue;

            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                negative[b[i] - 1] = true;
            }

            if (negative[a[i] - 1] == true) {
                negative[b[i] - 1] = true;
            }
        }
    }

    if (negative[N-1]) cout << "inf" << endl;
    else cout << -ans << endl;

    return 0;
}