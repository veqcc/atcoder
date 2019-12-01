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

    ll ans = 1;
    vector <int> count(1000005);
    count[0] = 3;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        ans = ans * count[a] % MOD;
        count[a]--;
        count[a + 1]++;
    }

    cout << ans << "\n";
    return 0;
}