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
    cin >> n;
    ll a[3 * n];
    ll pre = 0LL, pos = 0LL;
    priority_queue<ll, vector<ll>, greater<ll> > q1;
    priority_queue<ll> q2;
    for (int i = 0; i < 3 * n; i++) {
        cin >> a[i];
        if (i < n) {
            q1.push(a[i]);
            pre += a[i];
        } else if (i >= 2 * n) {
            q2.push(a[i]);
            pos += a[i];
        }
    }

    ll cost[n + 1];
    cost[0] = pre;
    for (int i = n; i < 2*n; i++) {
        q1.push(a[i]);
        pre += a[i] - q1.top();
        q1.pop();
        cost[i-n+1] = pre;
    }

    cost[n] -= pos;
    for (int i = 2*n-1; i >= n; i--) {
        q2.push(a[i]);
        pos += a[i] - q2.top();
        q2.pop();
        cost[i-n] -= pos;
    }

    cout << *max_element(cost, cost+n+1) << "\n";
    return 0;
}