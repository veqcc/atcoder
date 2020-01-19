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

    int ans = 0;
    int mn = 200005;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < mn) {
            ans++;
            mn = a;
        }
    }

    cout << ans << "\n";
    return 0;
}