#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <P> vec;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        vec.push_back(P(a, b));
    }

    sort(vec.begin(), vec.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].second <= m) {
            ans += vec[i].first * vec[i].second;
            m -= vec[i].second;
        } else {
            ans += vec[i].first * m;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}