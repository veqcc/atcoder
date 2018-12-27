#include <algorithm>
#include <iostream>
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

    ll N, A, B;
    cin >> N >> A >> B;
    ll X[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    ll ans = 0LL;
    for (int i = 0; i < N-1; i++) {
        ans += min(B, A * (X[i+1] - X[i]));
    }

    cout << ans << "\n";
    return 0;
}