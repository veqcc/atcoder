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

typedef pair<ll, ll> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <P> vec(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        vec[i] = P(b, a);
    }

    sort(vec.begin(), vec.end(), greater<P>());

    priority_queue <ll, vector<ll>, greater<ll> > q;
    ll ans = 0LL;
    ll sm = 0LL;
    for (int i = 0; i < n; i++) {
        if (q.size() == k) {
            sm -= q.top();
            q.pop();
        }

        q.push(vec[i].second);
        sm += vec[i].second;

        ans = max(ans, vec[i].first * sm);
    }

    cout << ans << '\n';
    return 0;
}