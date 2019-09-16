#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        q.push(a);
    }

    while (m--) {
        int p = q.top();
        q.pop();
        q.push(p / 2);
    }

    ll sum = 0;
    while (q.size()) {
        sum += q.top();
        q.pop();
    }

    cout << sum << "\n";
    return 0;
}