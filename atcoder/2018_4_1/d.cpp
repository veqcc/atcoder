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

    int n;
    ll C;
    cin >> n >> C;
    ll X[n], V[n];
    for (int i = 0; i < n; i++) {
        ll x, v;
        cin >> X[i] >> V[i];
    }

    ll forward[n], backward[n];
    forward[0] = V[0] - X[0];
    backward[n-1] = V[n-1] - C + X[n-1];
    for (int i = 1; i < n; i++) {
        forward[i] = forward[i-1] + V[i] - X[i] + X[i-1];
        backward[n-i-1] = backward[n-i] + V[n-i-1] + X[n-i-1] - X[n-i];
    }

    ll forward_and_return[n], backward_and_return[n];
    ll fmx = 0LL, bmx = 0LL;
    for (int i = 0; i < n; i++) {
        fmx = max(fmx, forward[i] - X[i]);
        forward_and_return[i] = fmx;
        bmx = max(bmx, backward[n-i-1] - C + X[n-i-1]);
        backward_and_return[n-i-1] = bmx;
    }

    ll ret = 0LL;
    for (int i = 0; i < n-1; i++) {
        ret = max(ret, forward[i] + backward_and_return[i+1]);
    }
    ret = max(ret, forward[n-1]);

    for (int i = 1; i < n; i++) {
        ret = max(ret, backward[i] + forward_and_return[i-1]);
    }
    ret = max(ret, backward[0]);

    cout << ret << "\n";
    return 0;
}