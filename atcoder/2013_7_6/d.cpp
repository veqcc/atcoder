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

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack <int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > a[i]) {
            st.pop();
            ans++;
        }

        if (st.empty() || st.top() < a[i]) {
            st.push(a[i]);
        }
    }

    cout << ans + st.size() << "\n";
    return 0;
}