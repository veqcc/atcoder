#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> alive;
    for (int i = 0; i < n; i++) {
        alive.insert(i);
    }

    int ans[n];
    fill(ans, ans+n, -1);

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;

        set<int>::iterator it = alive.lower_bound(l);
        vector<int> toErase;
        while (it != alive.end()) {
            int cur = *it;
            if (cur > r) break;

            if (cur != x) {
                toErase.push_back(cur);
                ans[cur] = x;
            }
            it++;
        }

        for (size_t j = 0; j < toErase.size(); j++) {
            alive.erase(toErase[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}