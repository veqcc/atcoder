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

    int n;
    cin >> n;

    vector <P> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end(), greater<P>());

    multiset <ll> st;
    st.insert(-1);
    st.insert(-1);
    st.insert(n);
    st.insert(n);
    st.insert(p[0].second);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ll val = p[i].second;

        auto itr = st.lower_bound(val);
        itr--;
        ll l1 = *itr;
        itr--;
        ll l2 = *itr;

        itr = st.lower_bound(val);
        ll r1 = *itr;
        itr++;
        ll r2 = *itr;

        ans += p[i].first * ((l1 - l2) * (r1 - val) + (val - l1) * (r2 - r1));

        st.insert(val);
    }

    cout << ans << "\n";
    return 0;
}