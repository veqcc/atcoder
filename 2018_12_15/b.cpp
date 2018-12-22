#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <iterator>
typedef long long ll;
typedef unsigned int uint;
using namespace std;


int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    multiset<ll> st;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        st.insert(a);
    }

    int ans = 0;
    while (!st.empty()) {
        ll mx = *--st.end();
        st.erase(--st.end());

        for (int i = 0; i <= 32; i++) {
            ll mn = (1LL << i) - mx;
            if (st.find(mn) != st.end()) {
                ans++;
                st.erase(st.find(mn));
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

