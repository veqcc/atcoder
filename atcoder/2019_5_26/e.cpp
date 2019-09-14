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

    int n, q;
    cin >> n >> q;

    vector <P> vec(2 * n);
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        vec[i] = P(s - x, x);
        vec[n + i] = P(t - x, -x);
    }

    sort(vec.begin(), vec.end());

    int idx = 0;
    set <int> st;
    while (q--) {
        int d;
        cin >> d;

        while (idx < vec.size() && vec[idx].first <= d) {
            int x = vec[idx++].second;
            if (x < 0) st.erase(-x);
            else st.insert(x);
        }

        if (st.size()) cout << *st.begin() << '\n';
        else cout << -1 << '\n';
    }

    return 0;


}