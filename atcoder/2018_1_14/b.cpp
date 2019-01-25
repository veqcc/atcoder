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

    int k;
    cin >> k;

    ll a[k];
    for (int i = 1; i <= k; i++) {
        cin >> a[k - i];
    }

    ll mn = 2;
    ll mx = 3;
    if (a[0] != 2LL) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i < k; i++) {
        if (mx / a[i] == mn / a[i] && mn % a[i] != 0LL && mx % a[i] != 0LL) {
            cout << -1 << endl;
            return 0;
        }

        if (mn % a[i] != 0LL) {
            mn = (mn / a[i] + 1) * a[i];
        }

        mx = mx / a[i] * a[i] + a[i] - 1;
    }

    cout << mn << " " << mx << "\n";
    return 0;
}