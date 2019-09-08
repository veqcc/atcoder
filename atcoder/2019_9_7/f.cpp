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

    int n;
    cin >> n;

    multiset <int, greater<int>> st;
    st.insert(0);

    for (int i = 0; i < (1 << n); i++) {
        int s;
        cin >> s;
        st.insert(s);
    }

    multiset <int, greater<int>> cur;
    cur.insert(*st.begin());
    st.erase(st.begin());

    for (int i = 0; i < n; i++) {
        vector <int> nxt;
        for (auto cur_itr = cur.begin(); cur_itr != cur.end(); cur_itr++) {
            int val = *cur_itr;
            auto itr = st.lower_bound(val - 1);

            if (*itr == 0) {
                cout << "No\n";
                return 0;
            }

            nxt.push_back(*itr);
            st.erase(itr);
        }

        for (int x : nxt) cur.insert(x);
    }

    cout << "Yes\n";
    return 0;
}