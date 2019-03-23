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
    int n;
    cin >> n;

    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        mx = max(mx, a);
        if (mx == i) {
            ans++;
            mx = 0;
        }
    }

    cout << ans << "\n";
    return 0;
}