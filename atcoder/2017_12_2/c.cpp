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
typedef pair <ll, ll> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue <P, vector<P>, greater<P>> q;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        q.push({a, b});
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        P p = q.top();
        q.pop();

        ans += p.first;
        q.push({p.first + p.second, p.second});
    }

    cout << ans << "\n";
    return 0;
}