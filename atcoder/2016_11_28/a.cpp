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

const ll mod = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    ll A[N], B[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A, A+N);
    sort(B, B+N);

    ll ans = 1LL, a = 0, b = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (b == N || A[a] < B[b]) {
            if (a < b) ans = ans * (b - a) % mod;
            a++;
        } else {
            if (b < a) ans = ans * (a - b) % mod;
            b++;
        }
    }

    cout << ans << "\n";
    return 0;
}