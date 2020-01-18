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

    vector <P> lr(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        lr[i].first = x + l;
        lr[i].second = x - l;
    }

    sort(lr.begin(), lr.end());

    int ans = 0;
    int cur = -MOD;
    for (P p : lr) {
        if (p.second >= cur) {
            ans++;
            cur = p.first;
        }
    }

    cout << ans << "\n";
    return 0;
}