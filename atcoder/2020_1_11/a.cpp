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

    vector <string> s(n);
    vector <int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }

    string X;
    cin >> X;

    int ans = 0;
    bool asleep = false;
    for (int i = 0; i < n; i++) {
        if (asleep) ans += t[i];
        if (s[i] == X) asleep = true;
    }

    cout << ans << "\n";
    return 0;
}