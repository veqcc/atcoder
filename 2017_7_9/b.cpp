#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    string ret = "NO";
    for (ll i = 0; i < N; i++) {
        ll mn = C * (N - 1 - i) - D * i;
        ll mx = D * (N - 1 - i) - C * i;
        if (B - A >= mn && B - A <= mx) {
            ret = "YES";
        }
    }

    cout << ret;
    return 0;
}