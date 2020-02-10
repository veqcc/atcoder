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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <P> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector <int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset <int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        st.insert(max(a[i + 1].first - b[i], 0));
    }

    vector <int> ans(n + 1);
    ans[a[0].second] = *st.begin();

    for (int c = 0; c < n; c++) {
        auto itr = st.lower_bound(max(a[c + 1].first - b[c], 0));
        st.erase(itr);
        st.insert(max(a[c].first - b[c], 0));
        ans[a[c + 1].second] = *st.begin();
    }

    for (int i = 0; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
    return 0;
}