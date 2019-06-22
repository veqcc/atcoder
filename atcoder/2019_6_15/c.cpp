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

    int a[n];
    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > 0) {
            pos.push_back(a[i]);
        } else if (a[i] <= 0) {
            neg.push_back(a[i]);
        }
    }

    int ans = 0;
    vector <P> ret;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    if (pos.size() == 0) {
        ans = neg[0];
        for (int i = 1; i < neg.size(); i++) {
            ret.push_back(P(ans, neg[i]));
            ans -= neg[i];
        }
    } else if (neg.size() == 0) {
        ans = pos[0];
        for (int i = 1; i < pos.size() - 1; i++) {
            ret.push_back(P(ans, pos[i]));
            ans -= pos[i];
        }
        ret.push_back(P(pos[pos.size() - 1], ans));
        ans = pos[pos.size() - 1] - ans;
    } else {
        ans = neg[0];
        for (int i = 0; i < pos.size() - 1; i++) {
            ret.push_back(P(ans, pos[i]));
            ans -= pos[i];
        }
        ret.push_back(P(pos[pos.size() - 1], ans));
        ans = pos[pos.size() - 1] - ans;

        for (int i = 1; i < neg.size(); i++) {
            ret.push_back(P(ans, neg[i]));
            ans -= neg[i];
        }
    }

    cout << ans << '\n';
    for (P p : ret) cout << p.first << " " << p.second << "\n";

    return 0;
}