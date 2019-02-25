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

    int n;
    cin >> n;

    vector <int> vec[n];
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        a--;
        vec[a].push_back(i);
    }

    int t = 0, s = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        ans += abs(t - vec[i][0]);
        t = vec[i][0];

        ans += abs(s - vec[i][1]);
        s = vec[i][1];
    }

    cout << ans << "\n";
    return 0;
}